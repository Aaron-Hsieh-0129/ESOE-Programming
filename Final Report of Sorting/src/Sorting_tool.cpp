#include <iostream>
#include "Sorting_tool.h"
#include <cstdlib>
#include <cstring>
#include <vector>
#include <fstream>
#include <vector>

int heapSize;

// Constructor
SortingTool:: SortingTool() {}

// Selection Sort
void SortingTool::selectionsort(void *const base, size_t num, size_t size, int (*compar) (const void*, const void*)) {
	char *base_ptr = (char *) base;
	void *tmp = malloc(size);
	int min_index = 0;
	for (int i = 0; i < num - 1; i++) {
		min_index = i;
		for (int j = i + 1; j < num; j++) {
			if ((*compar) ((void *) (base_ptr + size * min_index), (void *) (base_ptr + size * j)) > 0) {
				min_index = j;
			}
		}
		memcpy(tmp, base_ptr + size * min_index, size);
		memcpy(base_ptr + size * min_index, base_ptr + size * i, size);
		memcpy(base_ptr + size * i, tmp, size);
	}
	free(tmp);
	return;
}

// Insertion Sort
void SortingTool::insertionsort(void *const base, size_t num, size_t size, int (*compar) (const void*, const void*)) {
	char *base_ptr = (char *) base;
	char *now;
	void *tmp = malloc(size);
	for (int j = 1; j < num; j++) {
		memcpy(tmp, base_ptr + j * size, size);
		int i = j - 1;
		while (i >= 0 && (*compar) ((void *) (base_ptr + i * size), (void *) tmp) > 0) {
			memcpy(base_ptr + (i + 1) * size, base_ptr + i * size, size);
			i--;
		}
		memcpy(base_ptr + (i + 1) * size, tmp, size);

	}
	free(tmp);
	return;
}


// Bubble Sort
void SortingTool::bubblesort(void *const base, size_t num, size_t size, int (*compar) (const void*, const void*)) {
	char *base_ptr = (char *) base;
	int i = num;
	void *tmp = malloc(size);
	while (i > 0) {
		for (int j = 0; j < i - 1; j++) {
			if ((*compar) ((void *) (base_ptr + j * size), (void *) (base_ptr + (j + 1) * size)) > 0) {
				memcpy(tmp, base_ptr + j * size, size);
				memcpy(base_ptr + j * size, base_ptr + (j + 1) * size, size);
				memcpy(base_ptr + (j + 1) * size, tmp, size);
			}
		}
		i--;
	}
	free(tmp);
	return;
}

// Heap sort method
void SortingTool::heapsort(void *const base, size_t num, size_t size, int (*compar) (const void*, const void*)) {
    // Build Max-Heap
    BuildMaxHeap(base, num, size, compar);
    void *tmp = malloc(size);
    char *base_ptr = (char *) base;
    for (int i = num-1; i >= 1; i--){
        memcpy(tmp, base_ptr, size);
		memcpy(base_ptr, base_ptr + i * size, size);
		memcpy(base_ptr + i * size, tmp, size);
        heapSize--;
        MaxHeapify(base, 0, num, size, compar);
    }
}

void SortingTool::MaxHeapify(void *const base, int root, size_t num, size_t size, int (*compar) (const void*, const void*)) {
    int l = (root+1) * 2 - 1;
    int r = (root+1) * 2 + 1 - 1;
    int largest;
    char *base_ptr = (char *) base;
    void *tmp = malloc(size);
    if (l <= heapSize && (*compar) ((void*) (base_ptr + l * size), (void *) (base_ptr + root * size)) > 0) largest = l;
    else largest = root;

    if (r <= heapSize && (*compar) ((void *) (base_ptr + r * size), (void *) (base_ptr + largest * size)) > 0) largest = r;
    
    if (largest != root){
        memcpy(tmp, base_ptr + root * size, size);
		memcpy(base_ptr + root * size, base_ptr + largest * size, size);
		memcpy(base_ptr + largest * size, tmp, size);
        MaxHeapify(base, largest, num, size, compar);
    }
    free(tmp);
}

void SortingTool::BuildMaxHeap(void *const base, size_t num, size_t size, int (*compar) (const void*, const void*)) {
	heapSize = num - 1;
    for (int i = num/2-1; i>=0; i--) {
        MaxHeapify(base, i, num, size, compar);
    }
}


// Quick Sort
void SortingTool::quicksort(void *const base, size_t num, size_t size, int (*compar) (const void*, const void*)) {
    QuickSortSubVector(base, 0, num - 1, num, size, compar);
}

int SortingTool::Partition(void *const base, int low, int high, size_t num, size_t size, int (*compar) (const void*, const void*)) {
	char *base_ptr = (char *) base;
	// cout << "low: " << low << endl;
	int i = low - 1;
	void *tmp = malloc(size);
	void *highV = malloc(size);
	memcpy(highV, base_ptr + high * size, size);
	// cout << "low: " << low << endl;
	// cout << "high: " << high << endl;
	for (int j = low; j < high; j++){
		if ((*compar) ((void *) (highV), (void *) (base_ptr + j * size)) >= 0) {
			i++;
			memcpy(tmp, base_ptr + i * size, size);
			memcpy(base_ptr + i * size, base_ptr + j * size, size);
			memcpy(base_ptr + j * size, tmp, size);
		}
	}
	// cout << "i2: " << i << endl;
	memcpy(tmp, base_ptr + (i+1) * size, size);
	memcpy(base_ptr + (i+1) * size, base_ptr + high * size, size);
	memcpy(base_ptr + high * size, tmp, size);
	free(tmp);
	free(highV);
	return i + 1;
}

void SortingTool::QuickSortSubVector(void *const base, int low, int high, size_t num, size_t size, int (*compar) (const void*, const void*)) {
	if (low < high){
		int q = Partition(base, low, high, num, size, compar);
		// cout << "q-1: " << q-1 << endl;
		QuickSortSubVector(base, low, q - 1, num, size, compar);
		// cout << "high: " << high << endl;
		QuickSortSubVector(base, q + 1, high, num, size, compar);
	}
	return;
}

int SortingTool::compareScore(const void * a, const void * b){
	Student *pa=(Student *)a;
	Student *pb=(Student *)b;
	return (pa->score - pb->score);
}

int SortingTool::compareID(const void * a, const void * b){
	Student *pa=(Student *)a;
	Student *pb=(Student *)b;
	return (pa->ID - pb->ID);
}

int SortingTool::compareFirstName(const void * a, const void * b){
	Student *pa=(Student *)a;
	Student *pb=(Student *)b;
	string A = pa->firstName;
	string B = pb->firstName;
	return strcmp(A.c_str(), B.c_str());
}

int SortingTool::compareLastName(const void * a, const void * b){
	Student *pa=(Student *)a;
	Student *pb=(Student *)b;
	string A = pa->lastName;
	string B = pb->lastName;
	return strcmp(A.c_str(), B.c_str());
}

int SortingTool::compareInt(const void * a, const void * b) {
	if ( *(int*)a <  *(int*)b ) return -1;
	if ( *(int*)a == *(int*)b ) return 0;
	if ( *(int*)a >  *(int*)b ) return 1;
	return -999;
}

int SortingTool::compareDouble(const void * a, const void * b) {
	if ( *(double*)a <  *(double*)b ) return -1;
	if ( *(double*)a == *(double*)b ) return 0;
	if ( *(double*)a >  *(double*)b ) return 1;
	return -999;
}