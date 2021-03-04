CXX=g++
CXXFLAGS= -g -Wall -std=c++11

OBJS = colorMain.o Color.o

all: colorMain

colorMain: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

colorMain.o: colorMain.cpp Color.h
	$(CXX) $(CXXFLAGS) -o $@ -c colorMain.cpp

Color.o: Color.cpp Color.h
	$(CXX) $(CXXFLAGS) -o $@ -c Color.cpp

clean:
	rm -f *.o colorMain