@echo off
g++ -I src/include -c main.cpp -c rubik/*.cpp 
g++ *.o -o rubik.exe -L src/lib -l sfml-graphics -l sfml-window -l sfml-system
START rubik.exe
exit