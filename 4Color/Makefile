CXX=g++
CXXFLAGS= -g -Wall -std=c++11

OBJS = coloring.o Color.o

all: coloring

coloring: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

coloring.o: coloring.cpp Color.h
	$(CXX) $(CXXFLAGS) -o $@ -c coloring.cpp

Color.o: Color.cpp Color.h
	$(CXX) $(CXXFLAGS) -o $@ -c Color.cpp

clean:
	rm -f *.o coloring
