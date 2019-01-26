CXX = g++
CXXFLAGS += -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

SRC1 = critter.cpp
SRC2 = grid.cpp
SRC3 = main.cpp
SRCS = ${SRC1} ${SRC2} ${SRC3}

PROG1 = Critter
PROGS = ${PROG1}

HEADER1 = critter.hpp
HEADER2 = grid.hpp
HEADERS = ${HEADER1} ${HEADER2}

TAR = cs162_ModuleA_alltope.tar.bz2

default:
	${CXX} ${SRCS} ${HEADERS} -o ${PROG1}
all:
	${CXX} ${CXXFLAGS} ${SRCS} ${HEADERS} -o ${PROG1}
tar:
	tar cvjf ${TAR} ${SRCS} ${HEADERS} makefile
clean:
	rm -f ${PROGS} *.o *~
