import os
import tkinter as tk
from tkinter import filedialog, messagebox

def pcm_to_c_array(pcm_path, header_path, array_name="audio_bytes", bytes_per_line=12):
    """Core logic to convert the PCM binary into a C header."""
    try:
        if not os.path.exists(pcm_path):
            return False, f"Error: The input file does not exist."

        with open(pcm_path, "rb") as f:
            raw_bytes = f.read()
        
        total_bytes = len(raw_bytes)
        guard_name = os.path.basename(header_path).replace(".", "_").upper() + "_INCLUDED"

        with open(header_path, "w") as f:
            f.write(f"#ifndef {guard_name}\n")
            f.write(f"#define {guard_name}\n\n")
            f.write("#include <stdint.h>\n\n")
            f.write(f"// Total size: {total_bytes} bytes\n")
            f.write(f"const uint8_t {array_name}[] = {{\n")
            
            for i in range(0, total_bytes, bytes_per_line):
                chunk = raw_bytes[i : i + bytes_per_line]
                hex_strings = [f"0x{b:02X}" for b in chunk]
                line_content = ", ".join(hex_strings)
                f.write(f"    {line_content},\n")
                
            f.write("};\n\n")
            f.write(f"const uint32_t {array_name}_len = {total_bytes};\n\n")
            f.write(f"#endif // {guard_name}\n")

        return True, f"Success!\nGenerated {os.path.basename(header_path)}\nSize: {total_bytes} bytes."
    except Exception as e:
        return False, f"An error occurred:\n{str(e)}"


class PCMConverterApp:
    def __init__(self, root):
        self.root = root
        self.root.title("PCM to C Array Converter")
        self.root.geometry("450x250")
        self.root.resizable(False, False)

        # File paths
        self.input_path = tk.StringVar()
        self.output_path = tk.StringVar()
        self.array_name = tk.StringVar(value="my_audio_track")

        self.setup_ui()

    def setup_ui(self):
        # --- Input File Row ---
        tk.Label(self.root, text="Input PCM File:").grid(row=0, column=0, padx=10, pady=15, sticky="w")
        tk.Entry(self.root, textvariable=self.input_path, width=30).grid(row=0, column=1, padx=5, pady=15)
        tk.Button(self.root, text="Browse", command=self.browse_input).grid(row=0, column=2, padx=5, pady=15)

        # --- Output File Row ---
        tk.Label(self.root, text="Output Header (.h):").grid(row=1, column=0, padx=10, pady=5, sticky="w")
        tk.Entry(self.root, textvariable=self.output_path, width=30).grid(row=1, column=1, padx=5, pady=5)
        tk.Button(self.root, text="Browse", command=self.browse_output).grid(row=1, column=2, padx=5, pady=5)

        # --- Array Name Row ---
        tk.Label(self.root, text="C Array Name:").grid(row=2, column=0, padx=10, pady=15, sticky="w")
        tk.Entry(self.root, textvariable=self.array_name, width=30).grid(row=2, column=1, padx=5, pady=15, sticky="w")

        # --- Convert Button ---
        tk.Button(self.root, text="Convert File", command=self.convert_file, bg="#4CAF50", fg="black", font=("Arial", 10, "bold")).grid(row=3, column=0, columnspan=3, pady=20)

    def browse_input(self):
        filename = filedialog.askopenfilename(
            title="Select PCM File",
            filetypes=(("PCM Audio Files", "*.pcm"), ("All Files", "*.*"))
        )
        if filename:
            self.input_path.set(filename)
            # Auto-fill output path based on input path
            auto_out = os.path.splitext(filename)[0] + ".h"
            self.output_path.set(auto_out)

    def browse_output(self):
        filename = filedialog.asksaveasfilename(
            title="Save C Header As",
            defaultextension=".h",
            filetypes=(("C Header Files", "*.h"), ("All Files", "*.*"))
        )
        if filename:
            self.output_path.set(filename)

    def convert_file(self):
        # Validation
        in_path = self.input_path.get()
        out_path = self.output_path.get()
        arr_name = self.array_name.get()

        if not in_path or not out_path:
            messagebox.showwarning("Missing Info", "Please select both an input and output file.")
            return
        if not arr_name:
            messagebox.showwarning("Missing Info", "Please provide a name for the C array.")
            return

        # Run conversion
        success, message = pcm_to_c_array(in_path, out_path, array_name=arr_name)

        # Show result
        if success:
            messagebox.showinfo("Success", message)
        else:
            messagebox.showerror("Error", message)

if __name__ == "__main__":
    root = tk.Tk()
    app = PCMConverterApp(root)
    root.mainloop()