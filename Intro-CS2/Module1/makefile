CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

SRC1 = main.cpp
SRC2 = functions.cpp
SRCS = ${SRC1} ${SRC2}

HEADER1 = functions.hpp
HEADERS = ${HEADER1}

PROG1 = Module1
PROGS = ${PROG1}

TAR = cs162_Module1_alltope.tar.bz2

default:
	${CXX} ${SRCS} ${HEADERS} -o ${PROG1}

tar:
	tar cvfj ${TAR} ${SRCS} ${HEADERS} makefile
clean:
	rm -f ${PROGS} *.o *~
