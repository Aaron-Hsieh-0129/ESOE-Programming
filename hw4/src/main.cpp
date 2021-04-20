#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <fstream>
#include "Sorting_tool.h"

using namespace std;


void help_message(){
	cout << "usage: ./Sorting -[Score|ID|FirstName|LastName] -[SS|IS|BS] <output_file>" << endl;
}

int DataNumber = 0;

int main(int argc, char* argv[]){
	if (argc != 4){
		help_message();
		return 0;
	}

	//////////// read the input file /////////////
	string totalFirst, totalLast, totalScore, totalID;
	string tmpFirst, tmpLast;
	int tmpScore, tmpID;
	fstream fFirst("../data_generated/firstnamelist.txt");

	fFirst >> totalFirst;
	DataNumber = stoi(totalFirst);

	vector<Student> Class(DataNumber);
	
	for (int i = 0; i < DataNumber; i++){
		fFirst >> tmpFirst;
		Class[i].firstName = tmpFirst;
	}

	fstream fLast("../data_generated/lastnamelist.txt");
	fLast >> totalLast;
	for (int i = 0; i < DataNumber; i++){
		fLast >> tmpLast;
		Class[i].lastName = tmpLast;
	}

	fstream fScore("../data_generated/scorelist.txt");
	fScore >> totalScore;
	for (int i = 0; i < DataNumber; i++){
		fScore >> tmpScore;
		Class[i].score = tmpScore;
	}

	fstream fID("../data_generated/ID.txt");
	fID >> totalID;
	for (int i = 0; i < DataNumber; i++){
		fID >> tmpID;
		Class[i].ID = tmpID;
	}

	//////////// the sorting part ////////////////

	SortingTool SortingTool; // Constructor

	if(!strcmp(argv[1],"-Score")){
		if (!strcmp(argv[2],"-SS")) SortingTool.selectionsort(Class.data(), Class.size(), sizeof(Student), SortingTool.compareScore);
		else if (!strcmp(argv[2],"-IS")) SortingTool.insertionsort(Class.data(), Class.size(), sizeof(Student), SortingTool.compareScore);
		else if (!strcmp(argv[2],"-BS")) SortingTool.bubblesort(Class.data(), Class.size(), sizeof(Student), SortingTool.compareScore);
    }
    else if(!strcmp(argv[1],"-ID")){
        if (!strcmp(argv[2],"-SS")) SortingTool.selectionsort(Class.data(), Class.size(), sizeof(Student), SortingTool.compareID);
		else if (!strcmp(argv[2],"-IS")) SortingTool.insertionsort(Class.data(), Class.size(), sizeof(Student), SortingTool.compareID);
		else if (!strcmp(argv[2],"-BS")) SortingTool.bubblesort(Class.data(), Class.size(), sizeof(Student), SortingTool.compareID);
    }
    else if(!strcmp(argv[1], "-FirstName")){
    	if (!strcmp(argv[2],"-SS")) SortingTool.selectionsort(Class.data(), Class.size(), sizeof(Student), SortingTool.compareFirstName);
		else if (!strcmp(argv[2],"-IS")) SortingTool.insertionsort(Class.data(), Class.size(), sizeof(Student), SortingTool.compareFirstName);
		else if (!strcmp(argv[2],"-BS")) SortingTool.bubblesort(Class.data(), Class.size(), sizeof(Student), SortingTool.compareFirstName);
    }
    else if(!strcmp(argv[1],"-LastName")){
        if (!strcmp(argv[2],"-SS")) SortingTool.selectionsort(Class.data(), Class.size(), sizeof(Student), SortingTool.compareLastName);
		else if (!strcmp(argv[2],"-IS")) SortingTool.insertionsort(Class.data(), Class.size(), sizeof(Student), SortingTool.compareLastName);
		else if (!strcmp(argv[2],"-BS")) SortingTool.bubblesort(Class.data(), Class.size(), sizeof(Student), SortingTool.compareLastName);
    }
    else {
        help_message();
        return 0;
    }
    //////////// write the output file ///////////
    fstream fout(argv[3], ios::out);
    fout << "     ID" << "      FirstName" << "          LastName" << "     Score" << endl;
    for (int i = 0; i < DataNumber; i++){
        fout << setw(8) << Class[i].ID << "      " << setw(10) << Class[i].firstName << setw(16) << Class[i].lastName << setw(10) << Class[i].score << endl;
        
    }
    return 0;
}
