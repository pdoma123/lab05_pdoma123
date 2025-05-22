CXX = g++
CXXFLAGS = -Wall -std=c++17

all: examheap

examheap: examheap.o heap.o
	$(CXX) $(CXXFLAGS) -o examheap examheap.o heap.o

examheap.o: examheap.cpp
	$(CXX) $(CXXFLAGS) -c examheap.cpp

heap.o: heap.cpp
	$(CXX) $(CXXFLAGS) -c heap.cpp

clean:
	rm -f examheap.o heap.o examheap
