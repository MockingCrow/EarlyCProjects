CXX=g++
CXXFLAGS= -g -Wall -std=c++11

OBJS = Hashtable.o main.o

all: hash

hash: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

main.o: main.cpp Hashtable.h
	$(CXX) $(CXXFLAGS) -o $@ -c main.cpp

Hashtable.o: Hashtable.cpp Hashtable.h
	$(CXX) $(CXXFLAGS) -o $@ -c Hashtable.cpp

clean:
	rm -f *.o hash