CXX =g++
CXXFLAGS += -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

SRC1 = critter.cpp
SRC2 = main.cpp
SRC3 = grid.cpp
SRCS = ${SRC1} ${SRC2} ${SRC3}

HEADER1 = grid.hpp
HEADER2 = critter.hpp
HEADERS = ${HEADER1} ${HEADER2}

PROG1 = ModB
PROGS = ${PROG1}

TAR = cs162_ModuleB_alltope.tar.bz2

default:
	${CXX} ${SRCS} ${HEADERS} -o ${PROG1}
all:
	${CXX} ${CXXFLAGS} ${SRCS} ${HEADERS} -o ${PROG1}
tar:
	tar cvjf ${TAR} ${SRCS} ${HEADERS} makefile
clean:
	rm -f ${PROGS} *.o *~
