set SetINI=0
set SetComp=0
set FileINI=MySMcompile.ini
set FileComp=MySMcompile.exe
set FolderINI=
set FolderComp=
set curFolder=%cd%

:Start1
if SetINI==0 (
	if EXIST "%curFolder%\%FileINI%" (
	set SetINI=1
	set FileINI="%curFolder%\%FileINI%"
	echo FileINI="%curFolder%\%FileINI%"
	)
)	
if SetComp==0 (
	if EXIST "%curFolder%\%FileINI%" (
	set SetComp=1
	set FileINI="%curFolder%\%FileINI%"
	echo FileINI="%curFolder%\%FileINI%"
	)
)	
if SetINI==1 if SetComp==1 goto :Start2

goto Start1
:Start2


start "%FolderComp%" %FileComp% %1
:END

