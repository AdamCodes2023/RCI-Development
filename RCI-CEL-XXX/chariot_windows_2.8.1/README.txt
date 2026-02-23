   ____ _                _       _     __  __  ___ _____ _____   ____                           
  / ___| |__   __ _ _ __(_) ___ | |_  |  \/  |/ _ \_   _|_   _| / ___|  ___ _ ____   _____ _ __ 
 | |   | '_ \ / _` | '__| |/ _ \| __| | |\/| | | | || |   | |   \___ \ / _ \ '__\ \ / / _ \ '__|
 | |___| | | | (_| | |  | | (_) | |_  | |  | | |_| || |   | |    ___) |  __/ |   \ V /  __/ |   
  \____|_| |_|\__,_|_|  |_|\___/ \__| |_|  |_|\__\_\|_|   |_|   |____/ \___|_|    \_/ \___|_|   
                                                                                                
                                     
CHARIOT INSTALLATION

To install Chariot MQTT Server:
1. Unzip the chariot_windows.zip archive into C:\Program Files\Chariot folder 
2. Launch the 'Command Prompt' application as Administrator
3. In the 'Command Prompt', change to the C:\Program Files\Chariot folder and run the install.bat script
   as shown below:
   C:\Program Files\Chariot> install.bat
   

CHARIOT STARTUP

After Chariot MQTT Server is installed, the Chariot service can be launched as shown below: 
C:\Program Files\Chariot> serviceStart.bat

Note that the daemon is launched automatically on a system startup. 

To stop the Chariot service, run the serviceStop.bat script as shown below:
C:\Program Files\Chariot> serviceStop.bat


CHARIOT STATUS

To obtain the status of Chariot MQTT Server, run the status.bat script as shown below:
C:\Program Files\Chariot> status.bat

The status.bat script may return the following:
	RUNNING - Chariot daemon is running
	INSTALLED - Chariot is installed but the daemon is not running
	NOT INSTALLED - Chariot is not installed

For more detailed information on Chariot service run the queryService.bat script as shown below:
C:\Program Files\Chariot> yajsw/bat/queryService.bat


CHARIOT REMOTE CONNECTION

Apache Felix Remote Shell connection is available as shown below:
C:\Program Files\Chariot> telnet localhost 6666
