CXX = g++
CXXFLAGS += -std=c++0x
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

SRC1 = items.cpp
SRC2 = list.cpp
SRC3 = main.cpp
SRCS = ${SRC1} ${SRC2} ${SRC3}

HEADER1 = items.hpp
HEADER2 = list.hpp
HEADERS = ${HEADER1} ${HEADERS2}

PROG1 = ShoppingList
PROGS = ${PROG1}

TAR = cs162_Assignment2_alltope.tar.bz2

default:
	${CXX} ${SRCS} ${HEADERS} -o ${PROG1}
all:
	${CXX} ${CXXFLAGS} ${SRCS} ${HEADERS} -o ${PROG1}
tar:
	tar cvjf ${TAR} ${SRCS} ${HEADERS} makefile
clean:
	rm -f ${PROGS} *.o *~
