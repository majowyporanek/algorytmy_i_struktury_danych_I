CXXFLAGS = -Wall -Wextra
LDFLAGS = -Wall -Wextra
LDLIBS = -lm

.PHONY: alls
all: ArrayList.x CursorList.x

ArrayList.x: ArrayList.o
ArrayList.o: ArrayList.cpp ArrayList.hpp

CursorList.x: CursorList.o
CursorList.o: CursorList.cpp CursorList.hpp CursorList.hpp

%.x: %.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<