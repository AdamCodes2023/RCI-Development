:: Contains functions and constants to be used by other scripts

@echo off

:: Setting JAVA_HOME
set "JAVA_HOME=%~dp0lib\runtime\jdk17.0.15_6"
set PATH=%JAVA_HOME%\bin;%PATH%
::echo JAVA_HOME: %JAVA_HOME%

set CHARIOT_FOLDER_EXAMPLE=C:\Program Files\Chariot
set CHARIOT_STATUS_NOT_INSTALLED=NOT_INSTALLED
set CHARIOT_STATUS_INSTALLED=INSTALLED
set CHARIOT_STATUS_RUNNING=RUNNING
set "TAB=   "

call %*
goto :EOF

:: Otains status of the Chariot service
:obtainChariotStatus
set tmp_folder= C:\tmp\Chariot
set logFile=daemonStatus.log
set queryServiceFile=yajsw\bat\queryService.bat
set installed=0
set running=0

:: Setting up temporary folder
if not exist %tmp_folder% (
    mkdir %tmp_folder%
) else if exist %tmp_folder%\%logFile% (
    del %tmp_folder%\%logFile%
)

:: Quering Chariot service
call  "%~dp0%queryServiceFile%" > %tmp_folder%\%logFile% 2>&1
for /f "tokens=*" %%A in (%tmp_folder%\%logFile%) do (
    set "line=%%A"
    if "!line:~0,9!" == "Installed" (
	if "!line:~-4!" == "true" (
	    set installed=1
	)
    )
    if "!line:~0,7!" == "Running" (
	if "!line:~-4!" == "true" (
	    set running=1
	)
    )
)

:: Cleaning up
if exist %tmp_folder%\%logFile% (
    del %tmp_folder%\%logFile%
)

:: Setting return value
set %~1=%CHARIOT_STATUS_NOT_INSTALLED%
if %running% EQU 1 (
    set %~1=%CHARIOT_STATUS_RUNNING%
) else if %installed% EQU 1 (
    set %~1=%CHARIOT_STATUS_INSTALLED%
)
exit /B 0
