CXX = g++
CXXFLAGS += -std=c++0x
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
SRC1 = main.cpp
SRC2 = state.cpp
SRCS = ${SRC1} ${SRC2} 
HEADER1 = state.hpp
HEADERS = ${state.hpp}

PROG1 = traffic
PROGS = ${PROG1}

default: 
	${CXX} ${SRCS} ${HEADERS} -o ${PROG1}
all:
	${CXX} ${CXXFLAGS} ${SRCS} ${HEADERS} -o ${PROG1}
tar:
	tar cvjf ${TAR} ${SRCS} ${HEADERS} makefile
clean:
	rm -f ${PROGS} *.o *~
