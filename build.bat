@echo off

if not exist "build" mkdir build

g++ ^
    -std=c++17 ^
    -Isrc ^
    -pipe ^
    -g3 ^
    -grecord-gcc-switches ^
    -Wall ^
    -Wextra ^
    -Wshadow ^
    -Wundef ^
    -Wwrite-strings ^
    -Wcast-align ^
    -D_FORTIFY_SOURCE=2 ^
    -D_GLIBCXX_ASSERTIONS ^
    -fasynchronous-unwind-tables ^
    -fexceptions ^
    -Ofast ^
    -flto ^
    -o build\clockwork.exe ^
    src\*.cpp
