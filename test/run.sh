tput reset
rm -rf main
g++ -std=c++11 -o main main.cpp
/usr/bin/time -v  ./main

