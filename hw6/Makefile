CXX=g++
CXXFLAGS= -g -Wall -std=c++11

OBJS = Hashtable.o main.o

all: hash

counting: counting.o Hashtable.o
	$(CXX) $(CXXFLAGS) -o $@ counting.o Hashtable.o

hash: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

counting.o: counting.cpp Hashtable.h
	$(CXX) $(CXXFLAGS) -o $@ -c counting.cpp

main.o: main.cpp Hashtable.h
	$(CXX) $(CXXFLAGS) -o $@ -c main.cpp

Hashtable.o: Hashtable.cpp Hashtable.h
	$(CXX) $(CXXFLAGS) -o $@ -c Hashtable.cpp

clean:
	rm -f *.o hash