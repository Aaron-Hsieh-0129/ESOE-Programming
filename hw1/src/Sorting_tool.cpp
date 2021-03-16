#include <iostream>
#include "Sorting_tool.h"


// Constructor
SortingTool:: SortingTool() {}

void Swap(int *a, int *b){
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

// Selection Sort
void SortingTool::SelectionSort(vector<int>& data){
	int min_index = 0;
	for (int i = 0; i < data.size() - 1; i++){
		min_index = i;
		for (int j = i + 1; j < data.size(); j++){
			if (data[min_index] > data[j]){
				min_index = j;
			}
		}
		Swap(&data[min_index], &data[i]);
	}
	return;
}

// Insertion Sort
void SortingTool::InsertionSort(vector<int>& data){
	for (int j = 1; j < data.size(); j++){
		int tmp = data[j];
		int i = j - 1;
		while (i >= 0 && data[i] > tmp){
			data[i+1] = data[i];
			i--;
		}
		data[i+1] = tmp;
	}
	return;
}


// Bubble Sort
void SortingTool::BubbleSort(vector<int>& data){
	int i = data.size();
	while (i > 0){
		for (int j = 0; j < i; j++){
			if (data[j] > data[j+1]){
				Swap(&data[j], &data[j+1+1]);
			}
		}
		i--;
	}
	return;
}

// Merge Sort
void SortingTool::MergeSort(vector<int>& data){
    MergeSortSubVector(data, 0, data.size() - 1);
}

void SortingTool::Merge(vector<int>& data, int low, int middle, int high){
	int n1 = middle - low + 1;
	int n2 = high - middle;
	int L[n1];
	int R[n2];
	for (int i = 0; i < n1; i++){
		L[i] = data[low+i];
	}
	for (int j = 0; j < n2; j++){
		R[j] = data[middle+j+1];
	}
	L[n1] = 1e8;
	R[n2] = 1e8;
	int i = 0, j = 0;
	for (int k = low; k <= high; k++){
		if (L[i] <= R[j]){
			data[k] = L[i];
			i++;
		}else{
			data[k] = R[j];
			j++;
		}
	}
	return;
}

void SortingTool::MergeSortSubVector(vector<int>& data, int low, int high){
	if (low < high){
		int middle = (low + high) / 2;
		MergeSortSubVector(data, low, middle);
		MergeSortSubVector(data, middle + 1, high);
		Merge(data, low, middle, high);
	}
	return;
}

// Quick Sort
void SortingTool::QuickSort(vector<int>& data){
    QuickSortSubVector(data, 0, data.size() - 1);
}

int SortingTool::Partition(vector<int>& data, int low, int high){
	int x = data[high];
	int i = low - 1;
	for (int j = low; j < high; j++){
		if (data[j] <= x){
			i++;
			Swap(&data[i], &data[j]);
		}
	}
	Swap(&data[i+1], &data[high]);
	return i + 1;
}

void SortingTool::QuickSortSubVector(vector<int>& data, int low, int high){
	if (low < high){
		int q = Partition(data, low, high);
		QuickSortSubVector(data, low, q - 1);
		QuickSortSubVector(data, q + 1, high);
	}
	return;
}