#!/usr/bin/env python3
"""
RCI-CEL MQTT Developer Dashboard
Formulated for RCI Systems running Firmware V1.0 up to V2.4+
"""

import tkinter as tk
from tkinter import ttk, scrolledtext, messagebox, filedialog
import threading
import time
import ssl
import os
import socket

# ==============================================================================
# 🚨 USER CONFIGURATION SECTION - CUSTOMIZE YOUR DETAILS HERE
# ==============================================================================
# The Preset buttons in the GUI will automatically populate using these values.

AWS_CONFIG = {
    "broker": "a1917s4uqycwx-ats.iot.us-east-1.amazonaws.com",  # Your AWS IoT Core Endpoint
    "port": 8883,
    "ca_path": "C:/Users/Pribusin/Documents/Pribusin Software/RCI-XXX M5Stack/RCI-Development/RCI-CEL-XXX/AnchorCertificates/AmazonRootCA1.pem",       # Path to your Amazon Root CA 1
    "cert_path": "C:/Users/Pribusin/Downloads/AWS Update/connect_device_package/M5StackCore2.cert.pem",       # Path to your RCI Client Certificate
    "key_path": "C:/Users/Pribusin/Downloads/AWS Update/connect_device_package/M5StackCore2.private.key",       # Path to your RCI Client Private Key
    "username": "",                      # AWS usually does not use a username/password
    "password": ""
}

AZURE_CONFIG = {
    "broker": "pribusinmqtt.eastus-1.ts.eventgrid.azure.net",  # Your Azure EventGrid Namespace Endpoint
    "port": 8883,
    "ca_path": "",       # Path to your Azure Broker CA
    "cert_path": "C:/Users/Pribusin/Downloads/AzureConnectPackage/M5StackAzureSSL.pem",       # Path to your RCI Client Certificate
    "key_path": "C:/Users/Pribusin/Downloads/AzureConnectPackage/M5StackAzureSSL.key",       # Path to your RCI Client Private Key
    "username": "M5StackAzureSSL",      
    "password": ""			# Azure usually does not use a password
}

FLESPI_CONFIG = {
    "broker": "mqtt.flespi.io",
    "port": 8883,
    # Standard Flespi tokens from your developer documentation (Uncomment/set your active one):
    "token_1": "rQ3ccuJ9a1Ziz51qQ22UFyQJjjTiZQ7SZVBfWaVz0JGcav0PcglMPzhVoovRlBXn",
    "token_2": "DV3WrTTGCs3rVbodEeo16lApWWa63ll6Vgr0g098PWF7QoV6yK8pYJ3ZroVm8ugX",
    "token_3": "ZcFXjw1hHfWQX6Ygbq1jsJD1SBoQCTrvFJQJBpdsozb5TLNDYtKhnYgaRUKE6LRg",
    "active_token": "rQ3ccuJ9a1Ziz51qQ22UFyQJjjTiZQ7SZVBfWaVz0JGcav0PcglMPzhVoovRlBXn" # Selected default Flespi Token
}

DEFAULT_TARGETS = {
    "serial": "100001-03",  # Default Serial Number target for testing
    "group": "0011"         # Default Group ID target for testing
}
# ==============================================================================

class ScrollableFrame(ttk.Frame):
    def __init__(self, container, *args, **kwargs):
        super().__init__(container, *args, **kwargs)
        
        # Create a canvas and a vertical scrollbar for scrolling
        self.canvas = tk.Canvas(self, highlightthickness=0)
        scrollbar = ttk.Scrollbar(self, orient="vertical", command=self.canvas.yview)
        
        # Create the actual frame that will hold the widgets
        self.scrollable_frame = ttk.Frame(self.canvas)
        
        # Bind the size of the inner frame to the scroll region of the canvas
        self.scrollable_frame.bind(
            "<Configure>",
            lambda e: self.canvas.configure(scrollregion=self.canvas.bbox("all"))
        )
        
        # Create a window inside the canvas to hold the frame
        self.canvas_window = self.canvas.create_window((0, 0), window=self.scrollable_frame, anchor="nw")
        
        # Ensure the inner frame stretches to the width of the canvas
        self.canvas.bind(
            "<Configure>",
            lambda e: self.canvas.itemconfig(self.canvas_window, width=e.width)
        )
        
        self.canvas.configure(yscrollcommand=scrollbar.set)
        
        # Pack the canvas and scrollbar
        self.canvas.pack(side="left", fill="both", expand=True)
        scrollbar.pack(side="right", fill="y")

class RCIMQTTDashboard:
    def __init__(self, root):
        self.root = root
        self.root.title("RCI-CEL MQTT System Control Dashboard [V 1.1]")
        # Change height from 850+ down to a safer 700
        self.root.geometry("1100x700")
        self.root.minsize(950, 700)
        
        self.client = None
        self.connected = False
        
        # Thread-safe structures for tracking handshakes and queries
        self.active_events = {}   # topic -> (threading.Event, expected_payload, value_container)
        self.active_queries = {}  # topic -> (threading.Event, filter_function, value_container)
        
        self.create_styles()
        self.create_widgets()
        
        # Handle graceful exit on window close
        self.root.protocol("WM_DELETE_WINDOW", self.on_closing)

    def create_styles(self):
        self.style = ttk.Style()
        self.style.theme_use('clam')
        
        # Configure custom Frame and Label Frame backgrounds
        self.style.configure(".", font=("Segoe UI", 10))
        self.style.configure("TLabel", font=("Segoe UI", 10))
        self.style.configure("Header.TLabel", font=("Segoe UI", 12, "bold"))
        self.style.configure("Status.TLabel", font=("Segoe UI", 11, "bold"))

    def create_widgets(self):
        # --- Top Control Panel (Split into Target Specs and Broker Settings) ---
        top_frame = ttk.Frame(self.root, padding=10)
        top_frame.pack(side="top", fill="x")
        
        # Frame 1: Target Device Details
        target_frame = ttk.LabelFrame(top_frame, text=" 🎯 TARGET CONFIGURATION ", padding=10)
        target_frame.pack(side="left", fill="both", expand=True, padx=5)
        
        ttk.Label(target_frame, text="Serial Number:").grid(row=0, column=0, sticky="w", pady=5)
        self.entry_serial = ttk.Entry(target_frame, width=20)
        self.entry_serial.insert(0, DEFAULT_TARGETS["serial"])
        self.entry_serial.grid(row=0, column=1, sticky="w", padx=5, pady=5)
        
        ttk.Label(target_frame, text="Group ID:").grid(row=1, column=0, sticky="w", pady=5)
        self.entry_group = ttk.Entry(target_frame, width=20)
        self.entry_group.insert(0, DEFAULT_TARGETS["group"])
        self.entry_group.grid(row=1, column=1, sticky="w", padx=5, pady=5)
        
        # Frame 2: Connection Settings
        conn_frame = ttk.LabelFrame(top_frame, text=" 🌐 MQTT BROKER CONFIGURATION ", padding=10)
        conn_frame.pack(side="right", fill="both", expand=True, padx=5)
        
        # Subframe for Connection Presets
        presets_frame = ttk.Frame(conn_frame)
        presets_frame.grid(row=0, column=0, columnspan=5, sticky="ew", pady=2)
        ttk.Label(presets_frame, text="Presets:").pack(side="left", padx=5)
        
        ttk.Button(presets_frame, text="AWS IoT Preset", command=self.apply_aws_preset).pack(side="left", padx=5)
        ttk.Button(presets_frame, text="Azure EventGrid Preset", command=self.apply_azure_preset).pack(side="left", padx=2)
        ttk.Button(presets_frame, text="Flespi Token #1", command=lambda: self.apply_flespi_preset(1)).pack(side="left", padx=2)
        ttk.Button(presets_frame, text="Flespi Token #2", command=lambda: self.apply_flespi_preset(2)).pack(side="left", padx=2)
        ttk.Button(presets_frame, text="Flespi Token #3", command=lambda: self.apply_flespi_preset(3)).pack(side="left", padx=2)

        # Connection inputs
        ttk.Label(conn_frame, text="Host:").grid(row=1, column=0, sticky="w", pady=3)
        self.entry_broker = ttk.Entry(conn_frame, width=35)
        self.entry_broker.grid(row=1, column=1, columnspan=3, sticky="w", padx=5, pady=3)
        
        ttk.Label(conn_frame, text="Port:").grid(row=2, column=0, sticky="w", pady=3)
        self.entry_port = ttk.Entry(conn_frame, width=10)
        self.entry_port.grid(row=2, column=1, sticky="w", padx=5, pady=3)
        
        ttk.Label(conn_frame, text="Username:").grid(row=2, column=2, sticky="w", pady=3)
        self.entry_user = ttk.Entry(conn_frame, width=25)
        self.entry_user.grid(row=2, column=3, sticky="w", padx=5, pady=3)
        
        ttk.Label(conn_frame, text="Password:").grid(row=3, column=2, sticky="w", pady=3)
        self.entry_pass = ttk.Entry(conn_frame, width=25, show="*")
        self.entry_pass.grid(row=3, column=3, sticky="w", padx=5, pady=3)
        
        # SSL / TLS Settings
        self.var_ssl = tk.BooleanVar(value=True)
        self.check_ssl = ttk.Checkbutton(conn_frame, text="Enable SSL/TLS", variable=self.var_ssl)
        self.check_ssl.grid(row=3, column=0, columnspan=2, sticky="w", pady=3)
        
        # SSL File paths
        ttk.Label(conn_frame, text="CA Cert File:").grid(row=4, column=0, sticky="w", pady=2)
        self.entry_ca = ttk.Entry(conn_frame, width=30)
        self.entry_ca.grid(row=4, column=1, columnspan=2, sticky="ew", padx=5, pady=2)
        ttk.Button(conn_frame, text="Browse", command=lambda: self.browse_file(self.entry_ca)).grid(row=4, column=3, sticky="w", pady=2)
        
        ttk.Label(conn_frame, text="Client Cert:").grid(row=5, column=0, sticky="w", pady=2)
        self.entry_cert = ttk.Entry(conn_frame, width=30)
        self.entry_cert.grid(row=5, column=1, columnspan=2, sticky="ew", padx=5, pady=2)
        ttk.Button(conn_frame, text="Browse", command=lambda: self.browse_file(self.entry_cert)).grid(row=5, column=3, sticky="w", pady=2)
        
        ttk.Label(conn_frame, text="Client Key:").grid(row=6, column=0, sticky="w", pady=2)
        self.entry_key = ttk.Entry(conn_frame, width=30)
        self.entry_key.grid(row=6, column=1, columnspan=2, sticky="ew", padx=5, pady=2)
        ttk.Button(conn_frame, text="Browse", command=lambda: self.browse_file(self.entry_key)).grid(row=6, column=3, sticky="w", pady=2)
        
        # Connect / Disconnect Buttons
        btn_conn_frame = ttk.Frame(conn_frame)
        btn_conn_frame.grid(row=7, column=0, columnspan=4, sticky="ew", pady=8)
        
        self.btn_connect = ttk.Button(btn_conn_frame, text="🔌 CONNECT TO BROKER", command=self.connect_mqtt)
        self.btn_connect.pack(side="left", fill="x", expand=True, padx=5)
        
        self.btn_disconnect = ttk.Button(btn_conn_frame, text="🛑 DISCONNECT", command=self.disconnect_mqtt, state="disabled")
        self.btn_disconnect.pack(side="left", fill="x", expand=True, padx=5)
        
        # Visual Connection Status Indicator
        self.status_canvas = tk.Canvas(btn_conn_frame, width=20, height=20, highlightthickness=0)
        self.status_canvas.pack(side="right", padx=10)
        self.status_circle = self.status_canvas.create_oval(2, 2, 18, 18, fill="red")
        
        self.lbl_status = ttk.Label(btn_conn_frame, text="DISCONNECTED", style="Status.TLabel", foreground="red")
        self.lbl_status.pack(side="right", padx=5)

        # --- Bottom Scrolled Text Status Console ---
        console_frame = ttk.LabelFrame(self.root, text=" 📊 REAL-TIME STATUS & MQTT TRANSACTION TELEMETRY ", padding=10)
        # Setting expand to False forces it to respect its default height (e.g., height=10 or 12)
        console_frame.pack(side="bottom", fill="x", expand=False, padx=10, pady=10)
        
        # Reduce height from 12 lines to 8 lines to save vertical real estate
        self.txt_console = scrolledtext.ScrolledText(console_frame, height=8, font=("Consolas", 9), bg="#1e1e1e", fg="#00ff00", insertbackground="white")
        self.txt_console.pack(fill="both", expand=True)
        self.txt_console.configure(state="disabled")

        # --- Middle Notebook Controls ---
        self.notebook = ttk.Notebook(self.root, padding=5)
        self.notebook.pack(side="top", fill="both", expand=True, padx=10, pady=5)
        
        self.setup_queries_tab()
        self.setup_updates_tab()
        self.setup_logging_tab()
        self.setup_firmware_tab()
        
        # Populate defaults
        self.apply_aws_preset()

    # --- Tab Construction Helper Functions ---

    def setup_queries_tab(self):
        tab = ScrollableFrame(self.notebook, padding=10)
        self.notebook.add(tab, text=" 🔎 Status Queries ")
        
        ttk.Label(tab.scrollable_frame, text="Remotely retrieve telemetry and diagnostics directly from the device over MQTT:", style="Header.TLabel").pack(anchor="w", pady=5)
        
        btn_frame = ttk.Frame(tab.scrollable_frame, padding=5)
        btn_frame.pack(fill="both", expand=True, pady=10)
        
        # We assign button queries directly mapping topics to trigger requests
        ttk.Button(btn_frame, text="Query Software Version", width=30,
                   command=lambda: self.run_query_procedure("version", "Query Version")).grid(row=0, column=0, padx=10, pady=10)
        
        ttk.Button(btn_frame, text="Query Configuration Settings", width=30,
                   command=lambda: self.run_query_procedure("configDump", "Query Configuration Settings")).grid(row=0, column=1, padx=10, pady=10)
        
        ttk.Button(btn_frame, text="Query Cell Modem Serial Number", width=30,
                   command=lambda: self.run_query_procedure("modemSN", "Query Modem SN")).grid(row=1, column=0, padx=10, pady=10)
        
        ttk.Button(btn_frame, text="Query Cell Modem RSSI", width=30,
                   command=lambda: self.run_query_procedure("RSSI", "Query Modem RSSI")).grid(row=1, column=1, padx=10, pady=10)
                   
        ttk.Button(btn_frame, text="Check System Logging State", width=30,
                   command=lambda: self.run_query_procedure("logUpload", "Logging Status Check", payload="CHECK", is_log_check=True)).grid(row=2, column=0, padx=10, pady=10)

    def setup_updates_tab(self):
        tab = ScrollableFrame(self.notebook, padding=10)
        self.notebook.add(tab, text=" ⚙️ Configuration & Control ")
        
        ttk.Label(tab.scrollable_frame, text="Initiate configuration, internal detail updates, or reboot sequences (Under-the-Hood Handshaking):", style="Header.TLabel").pack(anchor="w", pady=5)
        
        btn_frame = ttk.Frame(tab.scrollable_frame, padding=5)
        btn_frame.pack(fill="both", expand=True, pady=10)
        
        ttk.Button(btn_frame, text="Update Configuration File (SerialNumber.txt)", width=35,
                   command=lambda: self.run_handshake_procedure("configUpdate", "Configuration File Update")).grid(row=0, column=0, padx=10, pady=15)
                   
        ttk.Button(btn_frame, text="Update Internal Info (internal.txt)", width=35,
                   command=lambda: self.run_handshake_procedure("internalUpdate", "Internal File Update")).grid(row=0, column=1, padx=10, pady=15)
                   
        ttk.Button(btn_frame, text="Update Cellular API Info (api.txt)", width=35,
                   command=lambda: self.run_handshake_procedure("apiUpdate", "API Details File Update")).grid(row=1, column=0, padx=10, pady=15)
                   
        ttk.Button(btn_frame, text="Reboot RCI-CEL Unit", width=35,
                   command=lambda: self.run_handshake_procedure("reboot", "Remote System Reboot")).grid(row=1, column=1, padx=10, pady=15)

    def setup_logging_tab(self):
        tab = ScrollableFrame(self.notebook, padding=10)
        self.notebook.add(tab, text=" 📝 Logging Management ")
        
        ttk.Label(tab.scrollable_frame, text="Manage remote telemetry logging options (Monthly reports saved to FTP Server):", style="Header.TLabel").pack(anchor="w", pady=5)
        
        # Logging State Controls Frame
        state_frame = ttk.LabelFrame(tab.scrollable_frame, text=" Log State (logUpload) ", padding=10)
        state_frame.pack(fill="x", pady=5)
        
        ttk.Button(state_frame, text="Enable Logging (ON)", width=25,
                   command=lambda: self.run_handshake_procedure("logUpload", "Enable Logging", final_payload="ON")).pack(side="left", padx=10, pady=5)
        ttk.Button(state_frame, text="Disable Logging (OFF)", width=25,
                   command=lambda: self.run_handshake_procedure("logUpload", "Disable Logging", final_payload="OFF")).pack(side="left", padx=10, pady=5)
                   
        # Request / Delete Log Frame
        action_frame = ttk.LabelFrame(tab.scrollable_frame, text=" On-Demand Log Request / Erasure ", padding=10)
        action_frame.pack(fill="x", pady=10)
        
        ttk.Label(action_frame, text="Date / Target Window (Format: YYYY/M, e.g., 2026/7):").grid(row=0, column=0, sticky="w", pady=5)
        self.entry_log_date = ttk.Entry(action_frame, width=15)
        self.entry_log_date.insert(0, "2026/7")
        self.entry_log_date.grid(row=0, column=1, sticky="w", padx=10, pady=5)
        
        ttk.Button(action_frame, text="Request On-Demand Log Upload", width=30,
                   command=self.execute_log_upload_request).grid(row=1, column=0, padx=5, pady=10, sticky="e")
                   
        ttk.Button(action_frame, text="Delete Log from Local Device Storage", width=30,
                   command=self.execute_log_delete_request).grid(row=1, column=1, padx=5, pady=10, sticky="w")

    def setup_firmware_tab(self):
        tab = ScrollableFrame(self.notebook, padding=10)
        self.notebook.add(tab, text=" 💾 Firmware Version Management ")
        
        # Create dual-panel structure dividing Firmware strategies
        left_frame = ttk.LabelFrame(tab.scrollable_frame, text=" PRIOR TO V 2.4 (THE OLD WAY) ", padding=10)
        left_frame.pack(side="left", fill="both", expand=True, padx=5, pady=5)
        
        desc_old = (
            "Under the legacy design (< V2.4), credentials and individual firmware updates "
            "rely on manually uploading files directly to individual folders on the FTP Server. "
            "This procedure begins a basic 1-4 Handshake to apply 'creds.txt' or 'update.bin'."
        )
        lbl_old = ttk.Label(left_frame, text=desc_old, wraplength=400, justify="left")
        lbl_old.pack(anchor="nw", pady=5)
        
        ttk.Button(left_frame, text="Perform Credentials & Firmware Update", width=35,
                   command=lambda: self.run_handshake_procedure("credUpdate", "Legacy Server Credentials / Firmware Update")).pack(side="bottom", fill="x", pady=15)
        
        right_frame = ttk.LabelFrame(tab.scrollable_frame, text=" INCLUDING & AFTER V 2.4 (THE NEW WAY) ", padding=10)
        right_frame.pack(side="right", fill="both", expand=True, padx=5, pady=5)
        
        desc_new = (
            "Version 2.4 introduces structural common folders on the FTP server for "
            "easier updates. File nomenclature format follows 'updateRCI-CEL_V#_#_#.bin'.\n\n"
            "An individual target will execute a handshake before checking files. "
            "A system-wide target updates the complete group instantly (no handshake)."
        )
        lbl_new = ttk.Label(right_frame, text=desc_new, wraplength=400, justify="left")
        lbl_new.pack(anchor="nw", pady=5)
        
        # Subframe for inputs
        new_ctrl_frame = ttk.Frame(right_frame)
        new_ctrl_frame.pack(fill="both", expand=True, pady=10)
        
        ttk.Label(new_ctrl_frame, text="Firmware Target (e.g. V LATEST or V 2.4):").grid(row=0, column=0, sticky="w", pady=5)
        self.entry_fw_version = ttk.Entry(new_ctrl_frame, width=15)
        self.entry_fw_version.insert(0, "V LATEST")
        self.entry_fw_version.grid(row=0, column=1, sticky="w", padx=5, pady=5)
        
        ttk.Button(new_ctrl_frame, text="Trigger Individual Firmware Update", width=35,
                   command=self.execute_modern_individual_update).grid(row=1, column=0, columnspan=2, sticky="ew", pady=10)
                   
        ttk.Button(new_ctrl_frame, text="Trigger System-Wide Group Update", width=35,
                   command=self.execute_group_system_update).grid(row=2, column=0, columnspan=2, sticky="ew", pady=5)

    # --- Presets and Helper Events ---

    def apply_aws_preset(self):
        self.entry_broker.delete(0, tk.END)
        self.entry_broker.insert(0, AWS_CONFIG["broker"])
        
        self.entry_port.delete(0, tk.END)
        self.entry_port.insert(0, str(AWS_CONFIG["port"]))
        
        self.entry_user.delete(0, tk.END)
        self.entry_user.insert(0, AWS_CONFIG["username"])
        
        self.entry_pass.delete(0, tk.END)
        self.entry_pass.insert(0, AWS_CONFIG["password"])
        
        self.var_ssl.set(True)
        
        self.entry_ca.delete(0, tk.END)
        self.entry_ca.insert(0, AWS_CONFIG["ca_path"])
        
        self.entry_cert.delete(0, tk.END)
        self.entry_cert.insert(0, AWS_CONFIG["cert_path"])
        
        self.entry_key.delete(0, tk.END)
        self.entry_key.insert(0, AWS_CONFIG["key_path"])
        
        self.log_message("AWS IoT Connection Preset Applied.")

    def apply_azure_preset(self):
        self.entry_broker.delete(0, tk.END)
        self.entry_broker.insert(0, AZURE_CONFIG["broker"])
        
        self.entry_port.delete(0, tk.END)
        self.entry_port.insert(0, str(AZURE_CONFIG["port"]))
        
        self.entry_user.delete(0, tk.END)
        self.entry_user.insert(0, AZURE_CONFIG["username"])
        
        self.entry_pass.delete(0, tk.END)
        self.entry_pass.insert(0, AZURE_CONFIG["password"])
        
        self.var_ssl.set(True)
        
        self.entry_ca.delete(0, tk.END)
        self.entry_ca.insert(0, AZURE_CONFIG["ca_path"])
        
        self.entry_cert.delete(0, tk.END)
        self.entry_cert.insert(0, AZURE_CONFIG["cert_path"])
        
        self.entry_key.delete(0, tk.END)
        self.entry_key.insert(0, AZURE_CONFIG["key_path"])
        
        self.log_message("Azure EventGrid Connection Preset Applied.")

    def apply_flespi_preset(self, token_index):
        self.entry_broker.delete(0, tk.END)
        self.entry_broker.insert(0, FLESPI_CONFIG["broker"])
        
        self.entry_port.delete(0, tk.END)
        self.entry_port.insert(0, str(FLESPI_CONFIG["port"]))
        
        token_key = f"token_{token_index}"
        self.entry_user.delete(0, tk.END)
        self.entry_user.insert(0, FLESPI_CONFIG[token_key])
        
        self.entry_pass.delete(0, tk.END)
        self.entry_pass.insert(0, "") # Flespi does not use a password
        
        self.var_ssl.set(True)
        
        # Standard system CA validation is sufficient for Flespi
        self.entry_ca.delete(0, tk.END)
        self.entry_cert.delete(0, tk.END)
        self.entry_key.delete(0, tk.END)
        
        self.log_message(f"Flespi Token #{token_index} Preset Applied.")

    def browse_file(self, entry_field):
        filepath = filedialog.askopenfilename()
        if filepath:
            entry_field.delete(0, tk.END)
            entry_field.insert(0, os.path.abspath(filepath))

    def log_message(self, text):
        def update_gui():
            self.txt_console.configure(state="normal")
            self.txt_console.insert(tk.END, f"[{time.strftime('%H:%M:%S')}] {text}\n")
            self.txt_console.see(tk.END)
            self.txt_console.configure(state="disabled")
        self.root.after(0, update_gui)

    def update_status_indicator(self, is_connected):
        def update_gui():
            if is_connected:
                self.status_canvas.itemconfig(self.status_circle, fill="green")
                self.lbl_status.config(text="CONNECTED", foreground="green")
                self.btn_connect.config(state="disabled")
                self.btn_disconnect.config(state="normal")
            else:
                self.status_canvas.itemconfig(self.status_circle, fill="red")
                self.lbl_status.config(text="DISCONNECTED", foreground="red")
                self.btn_connect.config(state="normal")
                self.btn_disconnect.config(state="disabled")
        self.root.after(0, update_gui)

    # --- Core MQTT Connection Functions ---

    def connect_mqtt(self):
        broker = self.entry_broker.get().strip()
        port_str = self.entry_port.get().strip()
        username = self.entry_user.get().strip()
        password = self.entry_pass.get().strip()
        use_ssl = self.var_ssl.get()
        ca_path = self.entry_ca.get().strip()
        cert_path = self.entry_cert.get().strip()
        key_path = self.entry_key.get().strip()
        
        if not broker or not port_str:
            messagebox.showerror("Error", "Broker Host and Port are required parameters.")
            return
            
        try:
            port = int(port_str)
        except ValueError:
            messagebox.showerror("Error", "Port must be an integer.")
            return

        def run_connection():
            self.log_message(f"Initiating network connection to {broker}:{port}...")

            # Fetch the user's computer name (hostname)
            hostname = socket.gethostname()
            
            # Combine your base static ID with the hostname
            # (e.g., "RCI_Dashboard_Admin_DESKTOP-JSMITH")
            my_static_id = f"RCI_Dashboard_Admin_{hostname}"
            
            try:
                # Dynamic handling to support Paho MQTT Library versions 1.x and 2.x
                try:
                    from paho.mqtt import client as mqtt
                    from paho.mqtt.enums import CallbackAPIVersion
                    self.client = mqtt.Client(client_id=my_static_id, callback_api_version=CallbackAPIVersion.VERSION2)
                except Exception:
                    import paho.mqtt.client as mqtt
                    self.client = mqtt.Client(client_id=my_static_id)
                    
                self.client.on_connect = self.on_connect
                self.client.on_disconnect = self.on_disconnect
                self.client.on_message = self.on_message
                
                if use_ssl:
                    try:
                        if cert_path and key_path:
                            # AWS Mutual TLS Config
                            self.client.tls_set(
                                ca_certs=ca_path if ca_path else None,
                                certfile=cert_path,
                                keyfile=key_path,
                                tls_version=ssl.PROTOCOL_TLSv1_2
                            )
                        else:
                            # Standard SSL connection (used by Flespi over Port 8883)
                            self.client.tls_set()
                    except Exception as tls_err:
                        self.log_message(f"SSL/TLS Config Error: {tls_err}")
                        return
                
                if username:
                    self.client.username_pw_set(username, password if password else None)
                
                # Connection attempts
                self.client.connect(broker, port, keepalive=60)
                self.client.loop_start()

                # --- ⏱️ NEW BROKER CONNECTION TIMEOUT LOGIC ---
                timeout_seconds = 10
                start_time = time.time()
                
                # Block this thread until connected or timeout is reached
                while not self.connected and (time.time() - start_time) < timeout_seconds:
                    time.sleep(0.2)
                    
                if not self.connected:
                    self.log_message(f"Broker connection timed out after {timeout_seconds} seconds.")
                    self.root.after(0, lambda: messagebox.showerror(
                        "Connection Timeout", 
                        f"Could not establish a connection to {broker} within {timeout_seconds} seconds.\n\nReturning to a neutral state."
                    ))
                    self.disconnect_mqtt() # Cleanly resets internal state
                # ----------------------------------------------

            except Exception as e:
                self.log_message(f"MQTT Connection Exception: {e}")
                self.update_status_indicator(False)

        threading.Thread(target=run_connection, daemon=True).start()

    def disconnect_mqtt(self):
        if self.client:
            self.client.loop_stop()
            self.client.disconnect()
            self.connected = False
            self.update_status_indicator(False)

    def on_connect(self, client, userdata, flags, rc, properties=None):
        # Resolve rc values consistently across client API versions
        rc_code = getattr(rc, "value", rc)
        if rc_code == 0:
            self.connected = True
            self.log_message("MQTT connection established successfully!")
            self.update_status_indicator(True)
        else:
            self.connected = False
            self.log_message(f"Connection failed. Reason code received: {rc_code}")
            self.update_status_indicator(False)

    def on_disconnect(self, client, userdata, *args, **kwargs):
        self.connected = False
        self.log_message("Disconnected from the MQTT Broker.")
        self.update_status_indicator(False)

    def on_message(self, client, userdata, msg):
        topic = msg.topic
        payload = msg.payload.decode('utf-8', errors='ignore')
        
        # Route standard handshake events
        if topic in self.active_events:
            event, expected_val, val_container = self.active_events[topic]
            if payload == expected_val:
                val_container[0] = payload
                event.set()
                
        # Route query event updates
        if topic in self.active_queries:
            event, filter_func, val_container = self.active_queries[topic]
            if filter_func(payload):
                val_container[0] = payload
                event.set()

    # --- Under the Hood Handshaking Engines (Queries and Sequence Procedures) ---

    def is_target_ready(self):
        if not self.connected or not self.client:
            messagebox.showwarning("Not Connected", "You must establish a connection to an MQTT Broker first.")
            return False
        if not self.entry_serial.get().strip():
            messagebox.showwarning("Missing Serial", "The target unit's Serial Number is required.")
            return False
        return True

    def wait_for_event(self, topic, expected, timeout=30):
        event = threading.Event()
        container = [None]
        self.active_events[topic] = (event, expected, container)
        success = event.wait(timeout)
        if topic in self.active_events:
            del self.active_events[topic]
        return success

    def wait_for_query_response(self, topic, filter_func, timeout=30):
        event = threading.Event()
        container = [None]
        self.active_queries[topic] = (event, filter_func, container)
        success = event.wait(timeout)
        result = container[0]
        if topic in self.active_queries:
            del self.active_queries[topic]
        return success, result

    def run_query_procedure(self, topic_suffix, action_name, payload="1", is_log_check=False):
        if not self.is_target_ready():
            return
            
        serial = self.entry_serial.get().strip()
        topic = f"{serial}_{topic_suffix}"
        
        def runner():
            self.log_message(f"Query Process Started: {action_name}")
            self.client.subscribe(topic)
            time.sleep(0.5) 
            
            self.client.publish(topic, payload, qos=1)
            self.log_message(f"[{topic}] Published query: {payload}")
            
            if is_log_check:
                #filter_func = lambda p: p in ["SYSTEM LOGGING ENABLED", "SYSTEM LOGGING DISABLED"]
                filter_func = lambda p: p != payload
            else:
                filter_func = lambda p: p != payload 

            # ⏱️ 10-Second Timeout Enforced Here
            success, response = self.wait_for_query_response(topic, filter_func, timeout=30)
            
            # Always unsubscribe to ensure a neutral state
            self.client.unsubscribe(topic)
            
            if success:
                self.log_message(f"[{topic}] RESULT RECEIVED: {response}")
                self.root.after(0, lambda: messagebox.showinfo("Query Successful", f"Result for {action_name}:\n\n{response}"))
            else:
                self.log_message(f"[{topic}] Transaction Error: Query timed out without response.")
                self.root.after(0, lambda: messagebox.showwarning(
                    "Device Timeout", 
                    f"The target unit ({serial}) did not respond to the query.\n\nAborted and returned to a neutral state."
                ))
            
            self.log_message(f"Query Process Finished: {action_name}")
            
        threading.Thread(target=runner, daemon=True).start()

    def run_handshake_procedure(self, topic_suffix, action_name, final_payload=None):
        if not self.is_target_ready():
            return
            
        serial = self.entry_serial.get().strip()
        topic = f"{serial}_{topic_suffix}"
        
        def runner():
            self.log_message(f"Handshake Sequence Started: {action_name}")
            self.client.subscribe(topic)
            time.sleep(0.5) 
            
            self.client.publish(topic, "1", qos=1)
            self.log_message(f"[{topic}] Step 1 -> Published: '1'")
            
            # ⏱️ Step 2 Timeout Check
            if not self.wait_for_event(topic, "2", timeout=30):
                self.log_message(f"[{topic}] TIMEOUT -> Failed to receive '2'. Handshake aborted.")
                self.client.unsubscribe(topic)
                self.root.after(0, lambda: messagebox.showwarning(
                    "Handshake Timeout", 
                    f"The target unit ({serial}) failed to respond to Step 1 of the handshake.\n\nAborted and returned to a neutral state."
                ))
                return
                
            self.log_message(f"[{topic}] Step 2 -> Received Response: '2'")
            self.client.publish(topic, "3", qos=1)
            self.log_message(f"[{topic}] Step 3 -> Published: '3'")
            
            # ⏱️ Step 4 Timeout Check
            if not self.wait_for_event(topic, "4", timeout=30):
                self.log_message(f"[{topic}] TIMEOUT -> Failed to receive '4'. Handshake aborted.")
                self.client.unsubscribe(topic)
                self.root.after(0, lambda: messagebox.showwarning(
                    "Handshake Timeout", 
                    f"The target unit ({serial}) failed to authenticate Step 3 of the handshake.\n\nAborted and returned to a neutral state."
                ))
                return
                
            self.log_message(f"[{topic}] Step 4 -> Received Response: '4' (Handshake Authenticated!)")
            
            if final_payload is not None:
                self.client.publish(topic, final_payload, qos=1)
                self.log_message(f"[{topic}] Step 5 -> Dispatched Final Command: '{final_payload}'")
                
            self.client.unsubscribe(topic)
            self.log_message(f"SUCCESS: {action_name} executed successfully.")
            
            # Optional: Show a success popup to let you know the action finished completely
            self.root.after(0, lambda: messagebox.showinfo("Success", f"{action_name} processed successfully."))
            
        threading.Thread(target=runner, daemon=True).start()

    # --- Specialty Procedure Triggers ---

    def execute_log_upload_request(self):
        target_date = self.entry_log_date.get().strip()
        if not target_date:
            messagebox.showwarning("Input Missing", "Please enter a target date (Format: YYYY/M).")
            return
        self.run_handshake_procedure("logUpload", f"Log Upload Request ({target_date})", final_payload=target_date)

    def execute_log_delete_request(self):
        target_date = self.entry_log_date.get().strip()
        if not target_date:
            messagebox.showwarning("Input Missing", "Please enter a target date (Format: YYYY/M).")
            return
        # Display explicit confirmation warning prior to storage erasures
        confirm = messagebox.askyesno("Confirm Deletion", f"This will delete system logs from local device storage for '{target_date}'. Proceed?")
        if confirm:
            self.run_handshake_procedure("logDelete", f"Log Storage Purge ({target_date})", final_payload=target_date)

    def execute_modern_individual_update(self):
        version_str = self.entry_fw_version.get().strip()
        if not version_str:
            messagebox.showwarning("Input Missing", "Please provide a target firmware version (e.g., V LATEST).")
            return
        self.run_handshake_procedure("credUpdate", f"Modern Individual Firmware Update ({version_str})", final_payload=version_str)

    def execute_group_system_update(self):
        if not self.connected or not self.client:
            messagebox.showwarning("Not Connected", "You must establish a connection to an MQTT Broker first.")
            return
        group_id = self.entry_group.get().strip()
        if not group_id:
            messagebox.showwarning("Input Missing", "The target Unit's Group ID is required for System-Wide Firmware Updates.")
            return
        version_str = self.entry_fw_version.get().strip()
        if not version_str:
            messagebox.showwarning("Input Missing", "Please provide a target firmware version (e.g., V LATEST).")
            return
            
        confirm = messagebox.askyesno("Confirm System-Wide Update", f"This is an instantly published action affecting ALL devices inside Group '{group_id}'.\nDo you want to dispatch update command: '{version_str}'?")
        if not confirm:
            return
            
        topic = f"{group_id}_systemVersion"
        
        def runner():
            self.log_message(f"Sending System-Wide Group Firmware Update command to Group '{group_id}'...")
            self.client.publish(topic, version_str, qos=1)
            self.log_message(f"[{topic}] Published payload: '{version_str}' (Sent directly without Handshake).")
            
        threading.Thread(target=runner, daemon=True).start()

    def on_closing(self):
        self.disconnect_mqtt()
        self.root.destroy()


if __name__ == "__main__":
    root = tk.Tk()
    app = RCIMQTTDashboard(root)
    root.mainloop()