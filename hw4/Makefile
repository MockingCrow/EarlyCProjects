CXX=g++
CXXFLAGS= -g -Wall -std=c++11

OBJS = floorplan.o

all: floorplan

floorplan: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

floorplan.o: floorplan.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c floorplan.cpp

clean:
	rm -f *.o floorplan