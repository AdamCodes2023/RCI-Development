'Imports files to upgrade from 2.0.0 to 2.1.0
Dim tmpFolder
Dim zipFileSelected
Dim file1, file1Src, folder1Dst
Dim file2, file2Src, folder2Dst
Dim file3, file3Src, folder3Dst

Set wshShell = WScript.CreateObject("WScript.Shell")

file1 = "embedded.mv.db"
file2 = "com.cirruslink.chariot.system.config"
file3 = "com.cirruslink.chariot.server.config"

tmpFolder = wshShell.CurrentDirectory & "\tmp\"

'Set source files
file1Src = tmpFolder & file1
file2Src = tmpFolder & file2
file3Src = tmpFolder & file3

'Set destination files
folder1Dst = wshShell.CurrentDirectory & "\h2\default\"
folder2Dst = wshShell.CurrentDirectory & "\conf\"
folder3Dst = wshShell.CurrentDirectory & "\conf\"

Set fso = CreateObject("Scripting.FileSystemObject")

'Check if ZIP file (full path) is passed as a command line argument
If WScript.Arguments.Count = 1 Then
    If fso.FileExists(WScript.Arguments.Item(0)) Then
	'Set ZIP file from command line argument
	zipFileSelected = WScript.Arguments.Item(0)
    End If
End If

' If ZIP file is not passed as a command line argument, select one to upload and extract
If Len(zipFileSelected) = 0 Then 
    Set wShell=CreateObject("WScript.Shell")
    Set oExec=wShell.Exec("mshta.exe ""about:<input type=file id=FILE><script>FILE.click();new ActiveXObject('Scripting.FileSystemObject').GetStandardStream(1).WriteLine(FILE.value);close();resizeTo(0,0);</script>""")
    zipFileSelected = oExec.StdOut.ReadLine
End If

If StrComp(fso.GetExtensionName(zipFileSelected), "zip", vbTextCompare) <> 0 Then
    WScript.Echo "The " & zipFileSelected & " is not a ZIP file"
    WScript.Quit
End If

'Create a tmp folder if doesn't exist
If NOT fso.FolderExists(tmpFolder) Then
    fso.CreateFolder(tmpFolder)
End If

'Extract selected ZIP file into tmp folder
Set objShell = CreateObject("Shell.Application")
Set FilesInZip = objShell.NameSpace(zipFileSelected).items
objShell.NameSpace(tmpFolder).CopyHere(FilesInZip)

Sub BuildFullPath(ByVal fullPath)
    If Not fso.FolderExists(fullPath) Then
	BuildFullPath fso.GetParentFolderName(fullPath)
	fso.CreateFolder fullPath
    End If
End Sub

'A subroutine to move a file
Sub moveFile(src,dst)
    If fso.FileExists(src) Then
	If NOT fso.folderExists(dst) Then
	    BuildFullPath dst
	End If
	fso.CopyFile src, dst, True
	fso.DeleteFile src
    Else
	 WScript.Echo "Required " & src & " file doesn't exist in specified ZIP archive" 
    End If
End Sub

'Move upgrade files to destinations
Call moveFile(file1Src, folder1Dst)
Call moveFile(file2Src, folder2Dst)
Call moveFile(file3Src, folder3Dst)

Set fso = Nothing
Set objShell = Nothing
WScript.Echo "Chariot files imported from: " & zipFileSelected
