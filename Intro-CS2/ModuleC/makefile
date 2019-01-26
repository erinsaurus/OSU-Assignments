CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

SRC1 = ant.cpp
SRC2 = critter.cpp
SRC3 = grid.cpp
SRC4 = main.cpp
SRCS = ${SRC1} ${SRC2} ${SRC3} ${SRC4}

HEADER1 = ant.hpp
HEADER2 = critter.hpp
HEADER3 = grid.hpp
HEADERS = ${HEADER1} ${HEADER2} ${HEADER3}

PROG1 = ModC
PROGS = ${PROG1}

TAR = cs162_ModuleC_alltope.tar.bz2

default:
	${CXX} ${SRCS} ${HEADERS} -o ${PROG1}
all:
	${CXX} ${CXXFLAGS} ${SRCS} ${HEADERS} -o ${PROG1}
tar:
	cvjf ${TAR} ${SRCS} ${HEADERS} makefile
clean:
	rm -f ${PROGS} *.o *~
