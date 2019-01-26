CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

SRC1 = main.cpp
SRC2 = barbarian.cpp
SRC3 = medusa.cpp
SRC4 = babayaga.cpp
SRC5 = bluemen.cpp
SRC6 = harrypotter.cpp
SRC7 = menu.cpp
SRC8 = creature.cpp
SRC9 = tournament.cpp
SRCS = ${SRC1} ${SRC2} ${SRC3} ${SRC4} ${SRC5} ${SRC6} ${SRC7} ${SRC8} ${SRC9}

HEADER1 = barbarian.hpp
HEADER2 = medusa.hpp
HEADER3 = babayaga.hpp
HEADER4 = bluemen.hpp
HEADER5 = harrypotter.hpp
HEADER6 = menu.hpp
HEADER7 = creature.hpp
HEADER8 = tournament.hpp
HEADERS = ${HEADER1} ${HEADER2} ${HEADER3} ${HEADER4} ${HEADER5} ${HEADER6} ${HEADER7} ${HEADER8}

PROG1 = Battle
PROGS = ${PROG1}

TAR = cs162_assignment4_alltope.tar.bz2

default:
	${CXX} ${SRCS} ${HEADERS} -o ${PROG1}
all:
	${CXX} ${CXXFLAGS} ${SRCS} ${HEADERS} -o ${PROG1}
tar:
	tar cvjf ${TAR} ${SRCS} ${HEADERS} makefile
clean:
	rm -f ${PROGS} *.o *~
