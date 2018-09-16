#James Wilson (wilsjame)
#CS 162 Makefile

#variables
CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -c #-Wall
CXXFLAGS += -g
#CXXFLAGS += -pedantic-errors
#CXXFLAGS += -g #debugging info

objects = main.o inputValid.o main_menu.o player.o bag.o location.o state.o compass.o cockpit.o artifactSite.o tunguskaSite.o stonehengeSite.o gobekliTepeSite.o easterIsleSite.o failSite.o failFuelSite.o failAlignmentSite.o acaciaSite.o enlightenmentSite.o engine.o

all: main

main: $(objects)
	$(CXX) $(objects) -o main 

main.o: main.cpp inputValid.hpp main_menu.hpp engine.hpp
	$(CXX) $(CXXFLAGS) main.cpp

inputValid.o: inputValid.cpp inputValid.hpp 
	$(CXX) $(CXXFLAGS) inputValid.cpp

main_menu.o: main_menu.cpp main_menu.hpp 
	$(CXX) $(CXXFLAGS) main_menu.cpp

engine.o: engine.cpp engine.hpp player.hpp compass.hpp 
	$(CXX) $(CXXFLAGS) engine.cpp

player.o: player.cpp player.hpp bag.hpp
	$(CXX) $(CXXFLAGS) player.cpp

bag.o: bag.cpp bag.hpp 
	$(CXX) $(CXXFLAGS) bag.cpp

location.o: location.cpp location.hpp bag.hpp inputValid.hpp state.hpp 
	$(CXX) $(CXXFLAGS) location.cpp

state.o: state.cpp state.hpp inputValid.hpp
	$(CXX) $(CXXFLAGS) state.cpp

compass.o: compass.cpp compass.hpp  cockpit.hpp tunguskaSite.hpp stonehengeSite.hpp gobekliTepeSite.hpp easterIsleSite.hpp failFuelSite.hpp failAlignmentSite.hpp acaciaSite.hpp enlightenmentSite.hpp

	$(CXX) $(CXXFLAGS) compass.cpp

cockpit.o: cockpit.cpp cockpit.hpp location.hpp 
	$(CXX) $(CXXFLAGS) cockpit.cpp

acaciaSite.o: acaciaSite.cpp acaciaSite.hpp location.hpp 
	$(CXX) $(CXXFLAGS) acaciaSite.cpp

artifactSite.o: artifactSite.cpp artifactSite.hpp location.hpp bag.hpp
	$(CXX) $(CXXFLAGS) artifactSite.cpp

tunguskaSite.o: tunguskaSite.cpp tunguskaSite.hpp artifactSite.hpp
	$(CXX) $(CXXFLAGS) tunguskaSite.cpp

stonehengeSite.o: stonehengeSite.cpp stonehengeSite.hpp artifactSite.hpp
	$(CXX) $(CXXFLAGS) stonehengeSite.cpp

gobekliTepeSite.o: gobekliTepeSite.cpp gobekliTepeSite.hpp artifactSite.hpp
	$(CXX) $(CXXFLAGS) gobekliTepeSite.cpp

easterIsleSite.o: easterIsleSite.cpp easterIsleSite.hpp artifactSite.hpp
	$(CXX) $(CXXFLAGS) easterIsleSite.cpp



failSite.o: failSite.cpp failSite.hpp location.hpp 
	$(CXX) $(CXXFLAGS) failSite.cpp

failFuelSite.o: failFuelSite.cpp failFuelSite.hpp failSite.hpp
	$(CXX) $(CXXFLAGS) failFuelSite.cpp

failAlignmentSite.o: failAlignmentSite.cpp failAlignmentSite.hpp failSite.hpp
	$(CXX) $(CXXFLAGS) failAlignmentSite.cpp

enlightenmentSite.o: enlightenmentSite.cpp enlightenmentSite.hpp failSite.hpp
	$(CXX) $(CXXFLAGS) enlightenmentSite.cpp



clean: 
	rm -rf $(objects) main
