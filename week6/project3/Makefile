#James Wilson (wilsjame)
#CS 162 Project 3 Makefile

#variables
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -c #-Wall
#CXXFLAGS += -pedantic-errors
#CXXFLAGS += -g #debugging info

objects = main.o Game.o Creature.o Barbarian.o Vampire.o BlueMen.o Medusa.o HarryPotter.o

all: main

main: $(objects)
	$(CXX) $(objects) -o main 

main.o: main.cpp Game.hpp 
	$(CXX) $(CXXFLAGS) main.cpp

Game.o: Game.cpp Game.hpp Creature.hpp Barbarian.hpp Vampire.hpp BlueMen.o Medusa.o HarryPotter.o
	$(CXX) $(CXXFLAGS) Game.cpp

Creature.o: Creature.cpp Creature.hpp 
	$(CXX) $(CXXFLAGS) Creature.cpp

Barbarian.o: Barbarian.cpp Barbarian.hpp Creature.hpp
	$(CXX) $(CXXFLAGS) Barbarian.cpp

Vampire.o: Vampire.cpp Vampire.hpp Creature.hpp
	$(CXX) $(CXXFLAGS) Vampire.cpp

BlueMen.o: BlueMen.cpp BlueMen.hpp Creature.hpp
	$(CXX) $(CXXFLAGS) BlueMen.cpp

Medusa.o: Medusa.cpp Medusa.hpp Creature.hpp
	$(CXX) $(CXXFLAGS) Medusa.cpp

HarryPotter.o: HarryPotter.cpp HarryPotter.hpp Creature.hpp
	$(CXX) $(CXXFLAGS) HarryPotter.cpp

clean: 
	rm -rf $(objects) main
