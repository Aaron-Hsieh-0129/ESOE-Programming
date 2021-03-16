
#include "Sorting_tool.h"
#include <cstring>
#include <iostream>
#include <fstream>

using namespace std;

void help_message(){
	cout << "usage: ./Sorting -[SS|IS|BS|MS|QS] <input_file> <output_file>" << endl;
	cout << "       SS - Selection Sort" << endl;
	cout << "       IS - Insertion Sort" << endl;
	cout << "       BS - Bubble Sort" << endl;
    cout << "       MS - Merge Sort" << endl;
    cout << "       QS - Quick Sort" << endl;
}

int main(int argc, char *argv[]){
	if (argc != 4){
		help_message();
		return 0;
	}

	//////////// read the input file /////////////
	char buffer[200];
    fstream fin(argv[2]);
    fstream fout(argv[3], ios::out);
    //fout.open(argv[3],ios::out);
    fin.getline(buffer,200);
    fin.getline(buffer,200);
    int junk, num;
    vector<int> data;
    while (fin >> junk >> num){
        data.push_back(num);
    }

    //////////// the sorting part ////////////////
    SortingTool SortingTool;
    if(!strcmp(argv[1],"-SS")){
        SortingTool.SelectionSort(data);
    }
    else if(!strcmp(argv[1],"-IS")){
        SortingTool.InsertionSort(data);
    }
    else if(!strcmp(argv[1], "-BS")){
    	SortingTool.BubbleSort(data);
    }
    else if(!strcmp(argv[1],"-MS")){
        SortingTool.MergeSort(data);
    }
    else if(!strcmp(argv[1],"-QS")){
        SortingTool.QuickSort(data);
    }
    else {
        help_message();
        return 0;
    }
    
    //////////// write the output file ///////////
    fout << "# " << data.size() << " data points" <<endl;
    fout << "# index number" << endl;
    for (int i = 0; i < data.size(); i++){
        fout << i << " " << data[i] << endl;
    }
    fin.close();
    fout.close();
    return 0;

}