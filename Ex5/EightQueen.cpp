#include <iostream>
#include <vector>
#include <cstdlib> 

using namespace std;

#define N 8
int cc = 0; // count the number of the solution

// Prototype
void BackTrack(int* row, int* slash, int* backslash, int* Queen, int i);
int Check(int i, int j, int* row, int* slash, int* backslash);
void Print(int* Queen);

int main(void) {
    int row[N] = {0};
    int slash[2*N+1] = {0};  
    int backslash[2*N+1] = {0};
    int Queen[N] = {0}; 

    BackTrack(row, slash, backslash, Queen, 0); 
    cout << "Total number of the graph: " << cc << endl;
    return 0; 
} 

void BackTrack(int* row, int* slash, int* backslash, int* Queen, int i) { 
    if(i == N) {
        Print(Queen); 
    } 
    else { 
        for (int j = 0; j < N; j++) {
            if (Check(i, j, row, slash, backslash)) { 
                Queen[i] = j; 
                row[j] = slash[i+j] = backslash[i-j+N] = 1; 
                BackTrack (row, slash, backslash, Queen, i + 1); 
                row[j] = slash[i+j] = backslash[i-j+N] = 0;
            } 
        }
    }
}

int Check(int i, int j, int* row, int* slash, int* backslash) {
   return !(row[j] || slash[i + j] || backslash[i - j + N]);
}

void Print(int* Queen) {
    for (int b = 0; b < N; b++) {
        for (int a = 0; a < N; a++) {
            if (Queen[b] == a) {
                cout << "Q ";
            }
            else {
                cout << ". ";
            }
        }
        cout << endl;
    }
    cc++;
    cout << "=================="<< endl;
}