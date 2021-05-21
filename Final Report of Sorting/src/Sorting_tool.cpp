#include <iostream>
#include "Sorting_tool.h"
#include <cstdlib>
#include <cstring>
#include <vector>
#include <fstream>


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

