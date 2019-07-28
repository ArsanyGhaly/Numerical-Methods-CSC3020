@echo off
cls

set DRIVE_LETTER=%1:
set PATH=%DRIVE_LETTER%\TDM-GCC-64\bin;%DRIVE_LETTER%\TDM-GCC-64\wxWidgets-3.0.2\lib;c:\windows
set PROJECT_PATH=.

mingw32-make DRIVE_LETTER="%DRIVE_LETTER%" PROJECT_PATH="%PROJECT_PATH%"

PolyRegression Prob20-48.txt 2
PolyInterpolation Prob20-48.txt 2 7.5
