cc = g++
src = ./src

all:main.cpp ${src}/*.cpp
	${cc} main.cpp ${src}/*.cpp -fpermissive -std=c++11 -o main

	

