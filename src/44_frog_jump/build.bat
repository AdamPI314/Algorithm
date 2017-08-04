@echo off
REM call "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat" x64
call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvarsall.bat" x64     
set compilerflags=/Od /Zi /EHsc
set linkerflags=/OUT:solution.exe
set source=../../include/fileIO/fileIO.cpp ../../include/dataStructure/dataStructure.cpp ../../include/misc/misc.cpp

cl.exe %compilerflags% solution.cpp %source% /link %linkerflags%