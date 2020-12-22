@echo off
set home_path=G:/Github_Repositories/Cpp-Challenges/[Hard]/[#152][04142014]_MinimumSpanningTree
cd %home_path%
Rem -I/%home_path%/header -find .h/.hpp files
Rem -L/%home_path%/lib    -find .a/.o files
echo %home_path%/header
g++ -Wextra -O0 -c -I/%home_path%/header  main.cpp -o main.exe