:: Reports the status of Chariot MQTT server (i.e. 'NOT INSTALLED', 'INSTALLED', 'RUNNING')

@echo off
setlocal EnableExtensions EnableDelayedExpansion

cd /d %~dp0
call chariot-common.bat :obtainChariotStatus chariot_status
if %errorlevel% EQU 0 (
    echo %0: Current Chariot status: %chariot_status%
) else (
    echo %0: Failed to obtain Chariot status. ERRORLEVEL: %errorlevel%
)
::pause
exit /B %errorlevel%

