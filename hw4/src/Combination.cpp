#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> people;
vector<int> combination;

void Print(const vector<int>& v) {
	static int count = 0;
	for (int i = 0; i < v.size(); ++i) { 
  		cout << v[i] << " "; 
  	}
  	cout << endl;
}

void backtrace(int offset, int k) {
	if (k == 0) {
		Print(combination);
    	return;
    }
	for (int i = offset; i <= people.size() - k; ++i) {
		combination.push_back(people[i]);
		backtrace(i+1, k-1);
		combination.pop_back();
	}
}

void help_message() {
	cout << "usage: ./Combination <n> <k>" << endl;
	cout << "Ex: ./Combination 5 3" << endl;
}

int main(int argc, char* argv[]) {
	if (argc != 3) {
		help_message();
		return 1;
	}
	int n = stoi(argv[1]);
	int k = stoi(argv[2]);

	for (int i = 0; i < n; i++) { 
		people.push_back(i+1); 
	}
	backtrace(0, k);

	return 0;
}