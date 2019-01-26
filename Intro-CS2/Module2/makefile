CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

SRC1 = main.cpp
SRC2 = queue.cpp
SRC3 = stack.cpp
SRCS = ${SRC1} ${SRC2} ${SRC3}

HEADER1 = queue.hpp
HEADER2 = stack.hpp
HEADERS = ${HEADER1} ${HEADER2}

PROG1 = Mod2
PROGS = ${PROG1}

TAR = cs162_Module2_alltope.tar.bz2

default:
	${CXX} ${SRCS} ${HEADERS} -o ${PROG1}
all:
	${CXX} ${CXXFLAGS} ${SRCS} ${HEADERS} -o ${PROG1}
tar:
	tar cvjf ${TAR} ${SRCS} ${HEADERS} makefile
clean:
	rm -f ${PROGS} *.o *~
