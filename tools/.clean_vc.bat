::tools/.clean_vc.bat
@echo off
setlocal

if not defined GNU_SLNDIR goto :error
if not defined VS_VERSION goto :error
if not defined GNUDir set "GNUDir=%~dp0..\"
set "SLN_DIR=%GNUDir%vstudio\%GNU_SLNDIR%\"
set "COPY_BAT=%GNUDir%tools\.copy.bat"

echo Deleting %VS_VERSION% bin,dll,lib files ...
call "%COPY_BAT%" remove_ifexist "%GNUDir%bin\%GNU_SLNDIR%"
call "%COPY_BAT%" remove_ifexist "%GNUDir%dll\%GNU_SLNDIR%"
call "%COPY_BAT%" remove_ifexist "%GNUDir%lib\%GNU_SLNDIR%"

echo Deleting %VS_VERSION% bsc,pdb,map files ...
call "%COPY_BAT%" remove_ifexist "%GNUDir%bsc\%GNU_SLNDIR%"
call "%COPY_BAT%" remove_ifexist "%GNUDir%pdb\%GNU_SLNDIR%"
call "%COPY_BAT%" remove_ifexist "%GNUDir%pdb_pub\%GNU_SLNDIR%"
call "%COPY_BAT%" remove_ifexist "%GNUDir%map\%GNU_SLNDIR%"

echo Deleting %VS_VERSION% tmp files ...
call "%COPY_BAT%" remove_ifexist "%GNUDir%tmp\%GNU_SLNDIR%"

echo Deleting %VS_VERSION% generation files in GNU and LOCAL ...
call "%COPY_BAT%" remove_ifexist "%SLN_DIR%ipch"
call "%COPY_BAT%" remove_ifexist "%SLN_DIR%*.opensdf"
call "%COPY_BAT%" remove_ifexist "%SLN_DIR%*.sdf"
call "%COPY_BAT%" remove_ifexist "%SLN_DIR%*.suo"
call "%COPY_BAT%" remove_ifexist "%SLN_DIR%*.vcxproj.user"
for /f "delims=" %%i in ('dir /ad /b "%SLN_DIR%"') do if /i not "%GNU_SLNDIR%" == "vc10" call "%COPY_BAT%" remove_ifexist "%SLN_DIR%%%~i\*.vcxproj.user"
goto :eof

:error
echo It needs to be run from clean.bat
echo;
pause
goto :eof
