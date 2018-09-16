#James Wilson (wilsjame)
#CS 162 Lab4 Makefile

#variables
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -c #-Wall
#CXXFLAGS += -pedantic-errors
#CXXFLAGS += -g #debugging info

objects = main.o University.o Buildings.o People.o Student.o Instructor.o

all: main

main: $(objects)
	$(CXX) $(objects) -o main 

main.o: main.cpp University.hpp Student.hpp Instructor.hpp
	$(CXX) $(CXXFLAGS) main.cpp

University.o: University.cpp University.hpp Buildings.hpp People.hpp
	$(CXX) $(CXXFLAGS) University.cpp

Buildings.o: Buildings.cpp Buildings.hpp
	$(CXX) $(CXXFLAGS) Buildings.cpp

People.o: People.cpp People.hpp
	$(CXX) $(CXXFLAGS) People.cpp

Student.o: Student.cpp Student.hpp People.hpp
	$(CXX) $(CXXFLAGS) Student.cpp

Instructor.o: Instructor.cpp Instructor.hpp People.hpp
	$(CXX) $(CXXFLAGS) Instructor.cpp

clean: 
	rm -rf $(objects) main




