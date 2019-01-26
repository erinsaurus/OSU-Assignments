CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
CXXFLAGS += -foptimize-sibling-calls

SRC1 = main.cpp
SRCS = ${SRC1}

PROG1 = Mod4
PROGS = ${PROG1}

TAR = cs162_Module4_alltope.tar.bz2

default:
	${CXX} ${CXXFLAGS} ${SRCS} -o ${PROG1}


all:
	${CXX} ${CXXFLAGS} ${SRCS} -o ${PROG1}

tar:
	tar cvjf ${TAR} ${SRCS} makefile
clean:
	rm -f ${PROGS} *.o *~
