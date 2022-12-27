CXXFLAGS = -Wall -Wextra
LDFLAGS = -Wall -Wextra
LDLIBS = -lm

.PHONY: all
all: Generator.x Stack.x ONP.x

Generator.x: Generator.o
Generator.o: Generator.cpp

Stack.x: Stack.o
Stack.o: Stack.cpp ArrayStack.hpp LinkedStack.hpp

ONP.x: ONP.o
ONP.o: ONP.cpp ArrayStack.hpp LinkedStack.hpp

%.x: %.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

