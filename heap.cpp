// heap.cpp
// Diba Mirza

#include "heap.h"
#include <iostream>
#include <utility>
using namespace std;

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
	vdata.push_back(value);

	if (vdata.size() == 1) {
		return;
	}

	int current = vdata.size() - 1;
	int parent = (current - 1) / 2;

	while (current > 0 && vdata[parent] > vdata[current]) {
		swap(vdata[parent], vdata[current]);
		current = parent;
		parent = (current - 1) / 2;
	}
	return;
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
	if (empty()) {
		return;
	}
	else if (vdata.size() == 1) {
		vdata.pop_back();
		return;
	}
	
	vdata[0] = vdata[vdata.size() - 1];
	vdata.pop_back();
	int current = 0;
	int size = vdata.size();
	int right; 
	int left; 

	while ((2 * current + 1) < size) {
		left = 2 * current + 1;
		if (left + 1 < size) {
			right = left + 1;
			if (vdata[current] > vdata[left] || vdata[current] > vdata[right]) {
				if (vdata[left] > vdata[right]) {
					swap(vdata[current], vdata[right]);
					current = right;
				}
				else {
					swap(vdata[current], vdata[left]);
					current = left;
				}
			}
			else {
				break;
			}
		}
		else {
			if (vdata[current] > vdata[left]) {
				swap(vdata[current], vdata[left]);
				current = left;
			}
			else {
				break;
			}
		}
	}
	return;

}

// Returns the minimum element in the heap
int Heap::top(){
  return vdata[0];
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  return vdata.empty();
}
    
