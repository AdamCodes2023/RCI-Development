:: Starts Chariot service

@echo off
setlocal EnableExtensions EnableDelayedExpansion

cd /d %~dp0
call chariot-common.bat :obtainChariotStatus chariot_status
if %chariot_status% EQU %CHARIOT_STATUS_INSTALLED% (
    echo %0: Starting Chariot service...
    call "%~dp0yajsw\bat\startService.bat"
    if %errorlevel% NEQ 0 (
	echo %0: Failed to start Chariot Service. ERRORLEVEL: %errorlevel%
	exit /B 1
    )
) else (
    if %chariot_status% EQU %CHARIOT_STATUS_RUNNING% (
	echo %0: Chariot service is currently running. To restart the service: & echo %TAB%%CHARIOT_FOLDER_EXAMPLE%^> serviceStop.bat & echo %TAB%%CHARIOT_FOLDER_EXAMPLE%^> serviceStart.bat 
    ) else if  %chariot_status% EQU %CHARIOT_STATUS_NOT_INSTALLED% (
		echo %0: Chariot is not installed. Please run:  & echo %TAB%%CHARIOT_FOLDER_EXAMPLE%^> install.bat & echo %TAB%%CHARIOT_FOLDER_EXAMPLE%^> serviceStart.bat 
    )
)
cd /d %~dp0
call chariot-common.bat :obtainChariotStatus chariot_status
echo %0: Current Chariot status: %chariot_status%
::pause
exit /b %errorlevel%

