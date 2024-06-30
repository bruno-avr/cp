@echo off
cls
if "%~x1"==".cpp" (
    g++ -std=c++17 -O2 "%~1"
) else (
    g++ -std=c++17 -O2 "%~1.cpp"
)
.\a.exe < .\in