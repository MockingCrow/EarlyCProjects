CXX=g++
CXXFLAGS= -g -Wall -std=c++11

OBJS = bayes.o

all: bayes

bayes: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

bayes.o: bayes.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c bayes.cpp

clean:
	rm -f *.o bayes