CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -g

SRC1 = main.cpp
SRC2 = street.cpp
SRC3 = bakery.cpp
SRC4 = butcher.cpp
SRC5 = cheese.cpp
SRC6 = chocolate.cpp
SRC7 = menu.cpp
SRC8 = player.cpp
SRC9 = produce.cpp
SRC10 = space.cpp
SRC11 = spices.cpp
SRC12 = wine.cpp
SRC13 = inventory.cpp
SRCS = ${SRC1} ${SRC2} ${SRC3} ${SRC4} ${SRC5} ${SRC6} ${SRC7} ${SRC8} ${SRC9} ${SRC10} ${SRC11} ${SRC12} ${SRC13} 

HEADER1 = bakery.hpp
HEADER2 = butcher.hpp
HEADER3 = cheese.hpp
HEADER4 = chocolate.hpp
HEADER5 = inventory.hpp
HEADER6 = menu.hpp
HEADER7 = player.hpp
HEADER8 = produce.hpp
HEADER9 = space.hpp
HEADER10 = spices.hpp
HEADER11 = street.hpp
HEADER12 = wine.hpp
HEADERS = ${HEADER1} ${HEADER2} ${HEADER3} ${HEADER4} ${HEADER5} ${HEADER6} ${HEADER7} ${HEADER8} ${HEADER9} ${HEADER10} ${HEADER11} ${HEADER12}

PROG1 = final
PROGS = ${PROG1}

TAR = cs162_FinalProject_alltope.tar.bz2

default:
	${CXX} ${SRCS} ${HEADERS} -o ${PROG1}
all:
	${CXX} ${CXXFLAGS} ${SRCS} ${HEADERS} -o ${PROG1}
tar:
	tar cvjf ${TAR} ${SRCS} ${HEADERS} makefile
clean:
	rm -f ${PROGS} *.o *~
