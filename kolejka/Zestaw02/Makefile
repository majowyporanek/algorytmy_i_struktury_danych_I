CXXFLAGS = -Wall -Wextra
LDFLAGS = -Wall -Wextra
LDLIBS = -lm

.PHONY: alls
all: Generator.x Queue.x Radix.x

Generator.x: Generator.o
Generator.o: Generator.cpp

Queue.x: Queue.o
Queue.o: Queue.cpp ArrayQueue.hpp LinkedQueue.hpp

Radix.x: Radix.o
Radix.o: Radix.cpp ArrayQueue.hpp LinkedQueue.hpp

%.x: %.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<
