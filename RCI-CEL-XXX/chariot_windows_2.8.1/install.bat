:: Installs Chariot  Chariot MQTT server

@echo off
setlocal EnableExtensions EnableDelayedExpansion

:: Obtain Chariot status
cd /d %~dp0
call chariot-common.bat :obtainChariotStatus chariot_status
if %errorlevel% NEQ 0 (
    echo %0: Failed to obtain Chariot status. ERRORLEVEL: %errorlevel%
    exit /B 1
)

if %chariot_status% EQU %CHARIOT_STATUS_NOT_INSTALLED% (
    echo %0: Installing Amazon Corretto
    powershell -Command "& {Expand-Archive -LiteralPath '%~dp0lib\runtime\amazon-corretto-17-x64-windows-jdk.zip' -DestinationPath '%~dp0lib\runtime\';}"
    if %errorlevel% NEQ 0 (
	echo %0: Failed to install Amazon Corretto. ERRORLEVEL: %errorlevel%
	exit /B 1
    )

    echo %0 Installing Chariot service
    call "%~dp0yajsw\bat\installService.bat"
    if %errorlevel% NEQ 0 (
	echo %0: Failed to install Chariot Service. ERRORLEVEL: %errorlevel%
	exit /B 1
    )
) else (
    if %chariot_status% EQU %CHARIOT_STATUS_INSTALLED% (
	echo %0: Chariot has already been installed.
    ) else if %chariot_status% EQU %CHARIOT_STATUS_RUNNING% (
	echo %0: Chariot has already been installed and is currently running.
    )
)

:: Obtain Chariot status again
cd /d %~dp0
call chariot-common.bat :obtainChariotStatus chariot_status
if %errorlevel% NEQ 0 (
    echo %0: Failed to obtain Chariot status. ERRORLEVEL: %errorlevel%
    exit /B 1
)

echo %0: Current Chariot status: %chariot_status%
if %chariot_status% EQU %CHARIOT_STATUS_INSTALLED% (
    echo %0: To launch Chariot service: & echo %TAB%%CHARIOT_FOLDER_EXAMPLE%^> serviceStart.bat
)

::pause
exit /b 0
