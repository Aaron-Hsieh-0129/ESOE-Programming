// Resource: https://www.geeksforgeeks.org/sudoku-backtracking-7/
#include <iostream>

using namespace std;

#define N 9

// Check whether it's complete
bool FindZero(int matrix[N][N], int& row, int& col) {
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (matrix[row][col] == 0) {
                return true;
            }
        }
    }
    return false;
}

// check Row
bool CheckRow(int matrix[N][N], int row, int num) {
    for (int col = 0; col < N; col++) {
        if (matrix[row][col] == num) {
            return true;
        }
    }
    return false;
}
 
bool CheckCol(int matrix[N][N], int col, int num)
{
    for (int row = 0; row < N; row++)
        if (matrix[row][col] == num)
            return true;
    return false;
}

bool CheckBox(int matrix[N][N], int boxStartRow, int boxStartCol, int num) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (matrix[row + boxStartRow][col + boxStartCol] == num) {
                return true;
            }
        }
    }
    return false;
}

// column, row, and box are all okay
bool Safe(int matrix[N][N], int row, int col, int num) {
    return !CheckRow(matrix, row, num) && !CheckCol(matrix, col, num) && 
    	   !CheckBox(matrix, row - row % 3, col - col % 3, num) && matrix[row][col] == 0;
}

// solve
bool SolveSudoku(int matrix[N][N]) {
    int row;
    int col;
 
    if (!FindZero(matrix, row, col)) {
        return true;
    }
 
    for (int num = 1; num <= N; num++) {
        if (Safe(matrix, row, col, num)) {
            matrix[row][col] = num;
 
	        if (SolveSudoku(matrix)) {
	            return true;
	        }
 
            matrix[row][col] = 0;
        }
    }
    return false;
}


void printmatrix(int matrix[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cout << matrix[row][col] << ", ";
        }
        cout << endl;
    }
}



int main(void) {
	int matrix[N][N] = {  
		{ 5,3,0,0,7,0,0,0,0 },
    	{ 6,0,0,1,9,5,0,0,0 },
        { 0,9,8,0,0,0,0,6,0 },
        { 8,0,0,0,6,0,0,0,3 },
        { 4,0,0,8,0,3,0,0,1 },
        { 7,0,0,0,2,0,0,0,6 },
        { 0,6,0,0,0,0,2,8,0 },
        { 0,0,0,4,1,9,0,0,5 },
        { 0,0,0,0,8,0,0,7,9 } 
    };

    if (SolveSudoku(matrix) == true) {
        printmatrix(matrix);
    }
    else {
        cout << "No solution exists" << endl;
    }
 
    return 0;
}
