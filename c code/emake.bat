@echo off
if not exist main_.c goto nofiles
echo compiling with BORLAND
bcc32 -tWC -q -w- -O2 -5 -a4 -IC:\BORLAND\BCC55\include -LC:\BORLAND\BCC55\lib camel.c @objfiles.lnk
if not exist camel.exe goto done
echo you can now execute: camel.exe
goto done
:nofiles
echo Run the translator to create new .c files
:done
