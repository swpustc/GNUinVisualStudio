::tools/.copy.bat
@echo off
setlocal

REM example: .copy.bat copy     "$(OutDir)$(TargetName).lib" "$(GNUlibDir)$(TargetName).lib" "$(GNUlibDir)"
REM example: .copy.bat xcopy    the same as copy
REM example: .copy.bat hardlink "$(OutDir)$(TargetName).lib" "$(GNUlibDir)$(TargetName).lib" "$(GNUlibDir)"
REM example: .copy.bat symbolic "$(OutDir)$(TargetName).lib" "$(GNUlibDir)$(TargetName).lib" "$(GNUlibDir)"
REM example: .copy.bat del   "$(GNUlibDir)$(TargetName).lib" "$(GNUbinDir)"
REM example: .copy.bat rmdir "$(GNUlibDir)" "$(GNUbinDir)"
REM example: .copy.bat rd    the same as rmdir
REM example: .copy.bat mkdir "$(GNUpdbDir)" "$(GNUpdb_publicDir)"
REM example: .copy.bat md    the same as mkdir
REM example: .copy.bat move   "$(OutDir)$(TargetName).lib"    "$(GNUlibDir)$(TargetName).lib" "$(GNUlibDir)"
REM example: .copy.bat rename "$(GNUlibDir)$(TargetName).lib" "$(TargetName).lib.backup"
REM example: .copy.bat ren    the same as rename
REM example: .copy.bat remove_ifexist tmp

if "%~1" == "" goto :error
if "%~2" == "" goto :error
set "copy_always=false"
set "src_suffix=%~f2"
if "%src_suffix%" == "" goto :error
if "%src_suffix:~-4,4%" == ".exe" set "copy_always=true"
if "%src_suffix:~-4,4%" == ".dll" set "copy_always=true"
if "%src_suffix:~-4,4%" == ".lib" set "copy_always=true"
set "FC_BIN=fc /a /l /lb32 /w"

:CopyBatLabel1
if /i not "%~1" == "copy" goto :CopyBatLabel2
  :CopyBatLabel_copy
  if not exist "%~f2" goto :error
  if "%~3" == "" goto :error
  if not "%~4" == "" ( if not exist "%~f4" mkdir "%~f4" )
  if not exist "%~f3" goto :CopyBatLabel_copy_2
  if "%copy_always%" == "true" goto :CopyBatLabel_copy_1
  fc /b "%~f2" "%~f3" > nul
  if "%errorlevel%" == "0" goto :end
  %FC_BIN% "%~f2" "%~f3"
  :CopyBatLabel_copy_1
  xcopy /d /y "%~f2" "%~f3"
  if "%errorlevel%" == "0" goto :end
  del "%~f3"
  :CopyBatLabel_copy_2
  copy "%~f2" "%~f3"
  goto :end

:CopyBatLabel2
if /i not "%~1" == "xcopy" goto :CopyBatLabel3
  :CopyBatLabel_xcopy
  goto :CopyBatLabel_copy

:CopyBatLabel3
if /i not "%~1" == "hardlink" goto :CopyBatLabel4
  :CopyBatLabel_hardlink
  if not exist "%~f2" goto :error
  if "%~3" == "" goto :error
  if not "%~4" == "" ( if not exist "%~f4" mkdir "%~f4" )
  if not exist "%~f3" goto :CopyBatLabel_hardlink_2
  if "%copy_always%" == "true" goto :CopyBatLabel_hardlink_1
  fc /b "%~f2" "%~f3" > nul
  if "%errorlevel%" == "0" goto :end
  %FC_BIN% "%~f2" "%~f3"
  :CopyBatLabel_hardlink_1
  del "%~f3"
  :CopyBatLabel_hardlink_2
  mklink /h "%~f3" "%~f2"
  goto :end

:CopyBatLabel4
if /i not "%~1" == "symbolic" goto :CopyBatLabel5
  :CopyBatLabel_symbolic
  if not exist "%~f2" goto :error
  if "%~3" == "" goto :error
  if not "%~4" == "" ( if not exist "%~f4" mkdir "%~f4" )
  if not exist "%~f3" goto :CopyBatLabel_symbolic_2
  if "%copy_always%" == "true" goto :CopyBatLabel_symbolic_1
  fc /b "%~f2" "%~f3" > nul
  if "%errorlevel%" == "0" goto :end
  %FC_BIN% "%~f2" "%~f3"
  :CopyBatLabel_symbolic_1
  del "%~f3"
  :CopyBatLabel_symbolic_2
  mklink /d "%~f3" "%~f2"
  goto :end

:CopyBatLabel5
if /i not "%~1" == "del" goto :CopyBatLabel6
  :CopyBatLabel_del
  if exist "%~f2" ( del "%~f2" )
  if not "%~3" == "" ( if exist "%~f3" rmdir "%~f3" )
  goto :end

:CopyBatLabel6
if /i not "%~1" == "rmdir" goto :CopyBatLabel7
  :CopyBatLabel_rmdir
  if exist "%~f2" ( rmdir "%~f2" )
  if not "%~3" == "" ( if exist "%~f3" rmdir "%~f3" )
  goto :end

:CopyBatLabel7
if /i not "%~1" == "rd" goto :CopyBatLabel8
  :CopyBatLabel_rd
  goto :CopyBatLabel_rmdir

:CopyBatLabel8
if /i not "%~1" == "mkdir" goto :CopyBatLabel9
  :CopyBatLabel_mkdir
  if not exist "%~f2" ( mkdir "%~f2" )
  if not "%~3" == "" ( if not exist "%~f3" mkdir "%~f3" )
  goto :end

:CopyBatLabel9
if /i not "%~1" == "md" goto :CopyBatLabel10
  :CopyBatLabel_md
  goto :CopyBatLabel_mkdir

:CopyBatLabel10
if /i not "%~1" == "move" goto :CopyBatLabel11
  :CopyBatLabel_move
  if not exist "%~f2" goto :end
  if "%~3" == "" goto :error
  if not "%~4" == "" ( if not exist "%~f4" mkdir "%~f4" )
  move "%~f2" "%~f3"
  goto :end

:CopyBatLabel11
if /i not "%~1" == "rename" goto :CopyBatLabel12
  :CopyBatLabel_rename
  if not exist "%~f2" goto :end
  if "%~3" == "" goto :error
  rename "%~f2" "%~3"
  goto :end

:CopyBatLabel12
if /i not "%~1" == "ren" goto :CopyBatLabel13
  :CopyBatLabel_ren
  goto :CopyBatLabel_rename

:CopyBatLabel13
if /i not "%~1" == "remove_ifexist" goto :CopyBatLabel14
  set "RETRY_TIMES=5"
  :CopyBatLabel_remove_ifexist
  if not exist "%~2\" goto :CopyBatLabel_remove_ifexist_1
  set /a RETRY_TIMES-=1
  if %RETRY_TIMES% lss 0 goto :error
  rd /s /q "%~2"
  goto :CopyBatLabel_remove_ifexist
  :CopyBatLabel_remove_ifexist_1
  if not exist "%~2" goto :CopyBatLabel_remove_ifexist_2
  set /a RETRY_TIMES-=1
  if %RETRY_TIMES% lss 0 goto :error
  del /f /a /q "%~2"
  goto :CopyBatLabel_remove_ifexist
  :CopyBatLabel_remove_ifexist_2
  if "%~3" == "" goto :end
  set "RETRY_TIMES=5"
  :CopyBatLabel_remove_ifexist_3
  if not exist "%~3\" goto :CopyBatLabel_remove_ifexist_4
  set /a RETRY_TIMES-=1
  if %RETRY_TIMES% lss 0 goto :error
  rd /s /q "%~3"
  goto :CopyBatLabel_remove_ifexist_3
  :CopyBatLabel_remove_ifexist_4
  if not exist "%~3" goto :CopyBatLabel_remove_ifexist_5
  set /a RETRY_TIMES-=1
  if %RETRY_TIMES% lss 0 goto :error
  del /f /a /q "%~3"
  goto :CopyBatLabel_remove_ifexist_3
  :CopyBatLabel_remove_ifexist_5
  if "%~4" == "" goto :end
  set "RETRY_TIMES=5"
  :CopyBatLabel_remove_ifexist_6
  if not exist "%~4\" goto :CopyBatLabel_remove_ifexist_7
  set /a RETRY_TIMES-=1
  if %RETRY_TIMES% lss 0 goto :error
  rd /s /q "%~4"
  goto :CopyBatLabel_remove_ifexist_6
  :CopyBatLabel_remove_ifexist_7
  if not exist "%~4" goto :CopyBatLabel_remove_ifexist_8
  set /a RETRY_TIMES-=1
  if %RETRY_TIMES% lss 0 goto :error
  del /f /a /q "%~4"
  goto :CopyBatLabel_remove_ifexist_6
  :CopyBatLabel_remove_ifexist_8
  goto :end

:CopyBatLabel14
:error
echo %~nx0 error, errorlevel: %errorlevel%
echo     $1: %1
if     "%~2" == ""                     set "file_exist=  "
if not "%~2" == "" if     exist "%~f2" set "file_exist=T:"
if not "%~2" == "" if not exist "%~f2" set "file_exist=F:"
echo %file_exist%  $2: %2
if     "%~3" == ""                     set "file_exist=  "
if not "%~3" == "" if     exist "%~f3" set "file_exist=T:"
if not "%~3" == "" if not exist "%~f3" set "file_exist=F:"
echo %file_exist%  $3: %3
if     "%~4" == ""                     set "file_exist=  "
if not "%~4" == "" if     exist "%~f4" set "file_exist=T:"
if not "%~4" == "" if not exist "%~f4" set "file_exist=F:"
echo %file_exist%  $4: %4

:end
cd .
