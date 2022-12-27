CXXFLAGS = -Wall -Wextra
LDFLAGS = -Wall -Wextra
LDLIBS = -lm

.PHONY: alls
all: BubbleSort.x InsertionSort.x SelectionSort.x Generator.x

Generator.x: Generator.o
Generator.o: Generator.cpp

BubbleSort.x: BubbleSort.o
BubbleSort.o: BubbleSort.cpp

InsertionSort.x: InsertionSort.o
InsertionSort.o: InsertionSort.cpp

SelectionSort.x: SelectionSort.o
SelectionSort.o: SelectionSort.cpp

%.x: %.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<