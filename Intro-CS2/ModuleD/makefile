CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

SRC1 = main.cpp
SRC2 = ant.cpp
SRC3 = critter.cpp
SRC4 = doodlebug.cpp
SRC5 = grid.cpp
SRCS = ${SRC1} ${SRC2} ${SRC3} ${SRC4} ${SRC5}

PROG1 = ModuleD
PROGS = ${PROG1}

TAR = cs162_ModuleD_alltope.tar.bz2

default:
	${CXX} ${SRCS} ${HEADERS} -o ${PROG1}
all:
	${CXX} ${CXXFLAGS} ${SRCS} ${HEADERS} -o ${PROG1}
tar:
	tar cvfj ${TAR} ${SRCS} ${HEADERS} makefile
clean:
	rm -f ${PROGS} *.o *~
