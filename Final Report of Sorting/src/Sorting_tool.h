#ifndef _SORTING_TOOL_H
#define _SORTING_TOOL_H

using namespace std;

typedef struct{
        string firstName;
        string lastName;
        int ID;
        size_t score;
}Student;

class SortingTool {
    public:
                    SortingTool(); // constructor
        void        selectionsort(void *const base, size_t num, size_t size, int (*compar) (const void*, const void*));            
        void        insertionsort(void *const base, size_t num, size_t size, int (*compar) (const void*, const void*));
        void        bubblesort(void *const base, size_t num, size_t size, int (*compar) (const void*, const void*));
        void        quicksort(void *const base, size_t num, size_t size, int (*compar) (const void*, const void*));
        void        heapsort(void *const base, size_t num, size_t size, int (*compar) (const void*, const void*));

        static void        MaxHeapify(void *const base, int root, size_t num, size_t size, int (*compar) (const void*, const void*));
        static void        BuildMaxHeap(void *const base, size_t num, size_t size, int (*compar) (const void*, const void*));
        static int         Partition(void *const base, int low, int high, size_t num, size_t size, int (*compar) (const void*, const void*));
        static void        QuickSortSubVector(void *const base, int low, int high, size_t num, size_t size, int (*compar) (const void*, const void*));
        static int         compareScore(const void * a, const void * b);
        static int         compareID(const void * a, const void * b);
        static int         compareFirstName(const void * a, const void * b);
        static int         compareLastName(const void * a, const void * b);
        static int         compareInt(const void * a, const void * b);
        static int         compareDouble(const void * a, const void * b);
};

#endif
