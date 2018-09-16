#James Wilson (wilsjame)
#CS 162 Lab3 Makefile
#define variables
CXX = g++ #C++ compiler
CXXFLAGS = -std=c++0x
CXXFLAGS += -c 
#-Wall
#CXXFLAGS += -pedantic-errors
#CXXFLAGS += -g #debugging info

objects = main.o Game.o Die.o LoadedDie.o

all: main

main: $(objects)
	$(CXX) $(objects) -o main

main.o: main.cpp Game.hpp 
	$(CXX) $(CXXFLAGS) main.cpp

Game.o: Game.cpp Game.hpp Die.hpp LoadedDie.hpp  
	$(CXX) $(CXXFLAGS) Game.cpp

Die.o: Die.cpp Die.hpp 
	$(CXX) $(CXXFLAGS) Die.cpp

LoadedDie.o: LoadedDie.cpp LoadedDie.hpp Die.hpp  
	$(CXX) $(CXXFLAGS) LoadedDie.cpp

clean:
	rm -rf $(objects) main
	


