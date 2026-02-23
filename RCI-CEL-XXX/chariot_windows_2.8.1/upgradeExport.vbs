'Export files to upgrade from 2.0.0 to 2.1.0

On Error Resume Next
Const FOF_CREATEPROGRESSDLG = &H0&

Dim ExportFile
Dim File1, File2, File3
Dim yy, mm, dd, hh, nn

Set wshShell = WScript.CreateObject("WScript.Shell")

'Files to export
file1 = wshShell.CurrentDirectory & "\h2\default\embedded.mv.db"
file2 = wshShell.CurrentDirectory & "\conf\com.cirruslink.chariot.system.config"
file3 = wshShell.CurrentDirectory & "\conf\com.cirruslink.chariot.server.config"

'Timestamp formatter
yy = Right("00" & Year(Date), 2)
mm = Right("00" & Month(Date), 2)
dd = Right("00" & Day(Date), 2)
hh = Right("00" & Hour(Time), 2)
nn = Right("00" & Minute(Time), 2)

Set fso = CreateObject("Scripting.FileSystemObject")

'Try copying the ~\h2\default\embedded.mv.db file to the ~\tmp folder to see if it is unlocked by Chariot 
fso.CopyFile file1, wshShell.CurrentDirectory & "\tmp\", True
If Err.Number <> 0 Then
    WScript.echo ("Chariot Export has failed..." & vbCrLf & "The " & file1 & " file is being used by Chariot. " & vbCrLf & "Run the serviceStop.bat first, then try running the upgradeExport.vbs script again.")
    WScript.Quit 1
Else
    fso.DeleteFile wshShell.CurrentDirectory & "\tmp\embedded.mv.db"
End If

'Form export ZIP file
exportFile = WshShell.CurrentDirectory & "\chariot_upgrade_" & yy & mm & dd & "_" & hh & nn & ".zip"
fso.CreateTextFile(exportFile, True).Write "PK" & Chr(5) & Chr(6) & String(18, vbNullChar)

'Add files to export ZIP archive
Set shellApp = CreateObject("Shell.Application")
With shellApp
    .NameSpace(exportFile).CopyHere file1, FOF_CREATEPROGRESSDLG
    WScript.Sleep 500
    .NameSpace(exportFile).CopyHere file2
    WScript.Sleep 500
    .NameSpace(exportFile).CopyHere file3
    WScript.Sleep 1000
End With

Set wshShell = Nothing
Set fso = Nothing
Set shellApp = Nothing

WScript.echo "Chariot files have been exported into: " & exportFile
