// resource: https://stackoverflow.com/questions/28711797/generating-n-choose-k-permutations-in-c
#include <iostream>
#include <string>
#include <vector>

using namespace std;


void help_message() {
    cout << "usage: ./Permutation <input>" << endl;
}

void PermGenerator(int n, int k) {    
    int d[] = {1,2,3,4,5,6,7,8,9};  
    sort(d, d+n);  
    do {  
        for (int i = 0; i < k; i++) {  
            cout << d[i] << " ";  
            if (i == k-1) cout << endl;  
        }  
    } while (next_permutation(d, d+n));  
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        help_message();
        return 1;
    }
    int n = stoi(argv[1]);
    int k = stoi(argv[2]);
    PermGenerator(n, k);
}