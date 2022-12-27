CXXFLAGS = -Wall -Wextra
LDFLAGS = -Wall -Wextra
LDLIBS = -lm

.PHONY: alls
all: Generator.x LinkedList.x

Generator.x: Generator.o
Generator.o: Generator.cpp

Queue.x: LinkedList
Queue.o: LinkedList.cpp LinkedList.hpp


%.x: %.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<