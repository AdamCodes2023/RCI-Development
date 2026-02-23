:: Stops Chariot service

@echo off
setlocal EnableExtensions EnableDelayedExpansion

cd /d %~dp0
call chariot-common.bat :obtainChariotStatus chariot_status
if %chariot_status% EQU %CHARIOT_STATUS_RUNNING% (
    echo %0: Stopping Chariot service...
    call "%~dp0yajsw\bat\stopService.bat"
     if %errorlevel% NEQ 0 (
	echo %0: Failed to stop Chariot Service. ERRORLEVEL: %errorlevel%
	exit /B 1
    )
) else (
    echo %0: Chariot service is not currently running.
)
cd /d %~dp0
call chariot-common.bat :obtainChariotStatus chariot_status
echo %0: Current Chariot status: %chariot_status%
::pause
exit /b %errorlevel%


