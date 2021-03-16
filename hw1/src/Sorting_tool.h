#ifndef _SORTING_TOOL_H
#define _SORTING_TOOL_H

#include <vector>
using namespace std;

class SortingTool {
    public:
                    SortingTool(); // constructor
        void        SelectionSort(vector<int>&);            
        void        InsertionSort(vector<int>&); // sort data using insertion sort
        void        BubbleSort(vector<int>&);
        void        MergeSort(vector<int>&); // sort data using merge sort
        void        QuickSort(vector<int>&); // sort data using quick sort
    private:
        void        QuickSortSubVector(vector<int>&, int, int); // quick sort subvector
        int         Partition(vector<int>&, int, int); // partition the subvector
        void        MergeSortSubVector(vector<int>&, int, int); // merge sort subvector
        void        Merge(vector<int>&, int, int, int); // merge two sorted subvector 
        
};

#endif
