CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

SRC1 = lastStart.cpp
SRCS = ${SRC1}

PROG1 = lastStart
PROGS = ${PROG1}


default:
	${CXX} ${SRCS} -o ${PROG1}
all:
	${CXX} ${CXXFLAGS} ${SRCS} -o ${PROG1}

clean:
	rm -f ${PROGS} *.o *~
