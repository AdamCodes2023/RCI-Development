:: Uninstalls Chariot MQTT server

@echo off
setlocal EnableExtensions EnableDelayedExpansion

:LoopStart
cd /d %~dp0
call chariot-common.bat :obtainChariotStatus chariot_status
if %errorlevel% NEQ 0 (
    echo %0: Failed to obtain Chariot status. ERRORLEVEL: %errorlevel%
    exit /B 1
)

if %chariot_status% EQU %CHARIOT_STATUS_NOT_INSTALLED% goto LoopEnd
    if %chariot_status% EQU %CHARIOT_STATUS_RUNNING% (
	echo %0: Stopping Chariot service...
	call "%~dp0yajsw\bat\stopService.bat"
	timeout /t 3 /nobreak > nul
    ) else if  %chariot_status% EQU %CHARIOT_STATUS_INSTALLED% (
	echo %0: Uninstalling Chariot service...
	call "%~dp0yajsw\bat\uninstallService.bat"
	if %errorlevel% NEQ 0 (
	    echo %0: Failed to uninstall Chariot Service. ERRORLEVEL: %errorlevel%
	    exit /B 1
	)

	echo %0: Removing the "%~dp0lib\runtime\jdk17.0.15_6 directory...
	if exist "%~dp0lib\runtime\jdk17.0.15_6" (
	    rmdir /s /q "%~dp0lib\runtime\jdk17.0.15_6"
	    if %errorlevel% NEQ 0 (
		echo %0: Failed to remove the "%~dp0lib\runtime\jdk17.0.15_6 directory. ERRORLEVEL: %errorlevel%
		exit /B 1
	    )
	)

	echo %0: Removing the "%~dp0h2 directory...
	if exist "%~dp0h2" (
	    rmdir /s /q "%~dp0h2"
	    if %errorlevel% NEQ 0 (
		echo %0: Failed to remove the "%~dp0h2 directory. ERRORLEVEL: %errorlevel%
		exit /B 1
	    )
	)

	echo %0: Removing the "%~dp0felix-cache directory...
	if exist "%~dp0felix-cache" (
	    rmdir /s /q "%~dp0felix-cache"
	    if %errorlevel% NEQ 0 (
		echo %0: Failed to remove the "%~dp0felix-cache directory. ERRORLEVEL: %errorlevel%
		exit /B 1
	    )
	)

	echo %0: Copying default configs...
	xcopy /s /y "%~dp0default" "%~dp0"
    )
goto LoopStart
:LoopEnd
echo %0: Current Chariot status: %chariot_status%
::pause
exit /b %errorlevel%

