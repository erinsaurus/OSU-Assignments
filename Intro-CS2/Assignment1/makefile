CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

SRC1 = Ant.cpp
SRC2 = aGrid.cpp
SRC3 = main.cpp
SRCS = ${SRC1} ${SRC2} ${SRC3}

HEADER1 = Ant.hpp
HEADER2 = aGrid.hpp
HEADERS = ${HEADER1} ${HEADER2}

PROG1 = ants
PROGS = ${PROG1}

TAR = cs162_assignment1_alltope.tar.bz2

default:
	${CXX} ${SRCS} ${HEADERS} -o ${PROG1}
all:
	${CXX} ${CXXFLAGS} ${SRCS} ${HEADERS} -o ${PROG1}
tar:
	tar cvjf ${TAR} ${SRCS} ${HEADERS} makefile
clean:
	rm -f ${PROGS} *.o *~
