CXX = g++
CXXFLAGS = -std=c++11 -Wall

OBJS = main.o LCS.o

main : ${OBJS}
	   ${CXX} $(CXXFLAGS) -o $@ ${OBJS}

clean :
		rm ${OBJS} main
