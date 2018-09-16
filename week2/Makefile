

CXX = g++ #C++ compiler
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall 
CXXFLAGS += -pedantic-errors 
CXXFLAGS += -g #debugging info

OBJS = functions.o lecture1.o

SRCS = functions.cpp lecture1.cpp

HEADERS = functions.hpp

#target: dependencies
#	rule to build
#	

lecture1: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o lecture1

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp} 

