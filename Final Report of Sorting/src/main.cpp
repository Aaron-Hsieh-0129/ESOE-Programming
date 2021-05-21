#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cstring>
#include <random>
#include "Sorting_tool.h"

using namespace std;


void help_message(){
	cout << "usage1 (Self-Defined Data): ./Sorting -[Score|ID|FirstName|LastName] -[SS|IS|BS] -[random|increasing|decreasing|semi] <size> <output_file>" << endl;
	cout << "Ex1: ./Sorting -Score -SS -random 1000 ../outputs/output.txt" << endl;
	cout << "usage2 (Normal Data): ./Sorting -[SS|IS|BS] <input_file> <output_fule>" << endl;
	cout << "Ex2: ./Sorting -SS ../generated_data/data_normal_generated/10_int_random.txt ../outputs/10_int_random.txt" << endl;
}

int DataNumber = 0;

int main(int argc, char* argv[]) {
	if (argc != 6 and argc != 4){
		help_message();
		return 0;
	}

	// This is Sorting of Large Data
	if (argc == 6) {
		vector<Student> Class(DataNumber);
		//////////// read the input file /////////////
		if (!strcmp(argv[3], "-random")) {
			string totalFirst, totalLast, totalScore, totalID;
			string tmpFirst, tmpLast;
			int tmpScore, tmpID;

			string root = "../generated_data/data_complex_generated/";
			string num = argv[4];
			string filename1 = num + "_firstnamelist_Random.txt";
			string input1 = root + filename1;
			fstream fFirst(input1);
			
			fFirst >> totalFirst;
			DataNumber = stoi(totalFirst);
			
			Class.resize(DataNumber);
			for (int i = 0; i < DataNumber; i++){
				fFirst >> tmpFirst;
				Class[i].firstName = tmpFirst;
			}

			string filename2 = num + "_lastnamelist_Random.txt";
			string input2 = root + filename2;
			fstream fLast(input2);
			fLast >> totalLast;
			for (int i = 0; i < DataNumber; i++){
				fLast >> tmpLast;
				Class[i].lastName = tmpLast;
			}

			string filename3 = num + "_scorelist_Random.txt";
			string input3 = root + filename3;
			fstream fScore(input3);
			fScore >> totalScore;
			for (int i = 0; i < DataNumber; i++){
				fScore >> tmpScore;
				Class[i].score = tmpScore;
			}

			string filename4 = num + "_ID_Random.txt";
			string input4 = root + filename4;
			fstream fID(input4);
			fID >> totalID;
			for (int i = 0; i < DataNumber; i++){
				fID >> tmpID;
				Class[i].ID = tmpID;
			}

		}

		else if (!strcmp(argv[3], "-increasing")) {
			string totalFirst, totalLast, totalScore, totalID;
			string tmpFirst, tmpLast;
			int tmpScore, tmpID;
			string num = argv[4];

			string root = "../generated_data/data_complex_generated/";
			string filename1 = num + "_firstnamelist_Increasing.txt";
			string input1 = root + filename1;
			fstream fFirst(input1);
			
			fFirst >> totalFirst;
			DataNumber = stoi(totalFirst);
			
			Class.resize(DataNumber);
			for (int i = 0; i < DataNumber; i++){
				fFirst >> tmpFirst;
				Class[i].firstName = tmpFirst;
			}

			string filename2 = num + "_lastnamelist_Increasing.txt";
			string input2 = root + filename2;
			fstream fLast(input2);
			fLast >> totalLast;
			for (int i = 0; i < DataNumber; i++){
				fLast >> tmpLast;
				Class[i].lastName = tmpLast;
			}

			string filename3 = num + "_scorelist_Increasing.txt";
			string input3 = root + filename3;
			fstream fScore(input3);
			fScore >> totalScore;
			for (int i = 0; i < DataNumber; i++){
				fScore >> tmpScore;
				Class[i].score = tmpScore;
			}

			string filename4 = num + "_ID_Increasing.txt";
			string input4 = root + filename4;
			fstream fID(input4);
			fID >> totalID;
			for (int i = 0; i < DataNumber; i++){
				fID >> tmpID;
				Class[i].ID = tmpID;
			}
		}

		else if (!strcmp(argv[3], "-decreasing")) {
			string totalFirst, totalLast, totalScore, totalID;
			string tmpFirst, tmpLast;
			int tmpScore, tmpID;
			string num = argv[4];

			string root = "../generated_data/data_complex_generated/";
			string filename1 = num + "_firstnamelist_Decreasing.txt";
			string input1 = root + filename1;
			fstream fFirst(input1);
			
			fFirst >> totalFirst;
			DataNumber = stoi(totalFirst);
			
			Class.resize(DataNumber);
			for (int i = 0; i < DataNumber; i++){
				fFirst >> tmpFirst;
				Class[i].firstName = tmpFirst;
			}

			string filename2 = num + "_lastnamelist_Decreasing.txt";
			string input2 = root + filename2;
			fstream fLast(input2);
			fLast >> totalLast;
			for (int i = 0; i < DataNumber; i++){
				fLast >> tmpLast;
				Class[i].lastName = tmpLast;
			}

			string filename3 = num + "_scorelist_Decreasing.txt";
			string input3 = root + filename3;
			fstream fScore(input3);
			fScore >> totalScore;
			for (int i = 0; i < DataNumber; i++){
				fScore >> tmpScore;
				Class[i].score = tmpScore;
			}

			string filename4 = num + "_ID_Decreasing.txt";
			string input4 = root + filename4;
			fstream fID(input4);
			fID >> totalID;
			for (int i = 0; i < DataNumber; i++){
				fID >> tmpID;
				Class[i].ID = tmpID;
			}
		}

		else if (!strcmp(argv[3], "-semi")) {
			string totalFirst, totalLast, totalScore, totalID;
			string tmpFirst, tmpLast;
			int tmpScore, tmpID;
			string num = argv[4];

			string root = "../generated_data/data_complex_generated/";
			string filename1 = num + "_firstnamelist_Semi.txt";
			string input1 = root + filename1;
			fstream fFirst(input1);
			
			fFirst >> totalFirst;
			DataNumber = stoi(totalFirst);
			
			Class.resize(DataNumber);
			for (int i = 0; i < DataNumber; i++){
				fFirst >> tmpFirst;
				Class[i].firstName = tmpFirst;
			}

			string filename2 = num + "_lastnamelist_Semi.txt";
			string input2 = root + filename2;
			fstream fLast(input2);
			fLast >> totalLast;
			for (int i = 0; i < DataNumber; i++){
				fLast >> tmpLast;
				Class[i].lastName = tmpLast;
			}

			string filename3 = num + "_scorelist_Semi.txt";
			string input3 = root + filename3;
			fstream fScore(input3);
			fScore >> totalScore;
			for (int i = 0; i < DataNumber; i++){
				fScore >> tmpScore;
				Class[i].score = tmpScore;
			}

			string filename4 = num + "_ID_Semi.txt";
			string input4 = root + filename4;
			fstream fID(input4);
			fID >> totalID;
			for (int i = 0; i < DataNumber; i++){
				fID >> tmpID;
				Class[i].ID = tmpID;
			}
		}

		else {
			cout << "please generate file at ../generated_data/data_complex_generated" << endl;
			return 0;
		}

		double START, END; 
		START = clock();
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

	    END = clock();
	    cout <<"The total CPU time: " << (END - START) << " ms" << endl;

	    //////////// write the output file ///////////
	    fstream fout(argv[5], ios::out);
	    fout << "     ID" << "      FirstName" << "          LastName" << "     Score" << endl;
	    for (int i = 0; i < DataNumber; i++){
	        fout << setw(8) << Class[i].ID << "      " << setw(10) << Class[i].firstName << setw(16) << Class[i].lastName << setw(10) << Class[i].score << endl;
	        
	    }
	    return 0;
	}    

	if (argc == 4) {
		fstream finput(argv[2]);

		string type;
		finput >> type;
		int DataNumber;
		finput >> DataNumber;

		if (type == "int") {
			// input
			vector<int> Data;
			int tmp;
			for (int i = 0; i < DataNumber; i++) {
				finput >> tmp;
				Data.push_back(tmp);
			}

			double START, END; 
			START = clock();
			// sort
			SortingTool SortingTool; // Constructor
			if (!strcmp(argv[1],"-SS")) SortingTool.selectionsort(Data.data(), Data.size(), sizeof(int), SortingTool.compareInt);
			else if (!strcmp(argv[1],"-IS")) SortingTool.insertionsort(Data.data(), Data.size(), sizeof(int), SortingTool.compareInt);
			else if (!strcmp(argv[1],"-BS")) SortingTool.bubblesort(Data.data(), Data.size(), sizeof(int), SortingTool.compareInt);

			END = clock();
	    	cout <<"The total CPU time: " << (END - START) << " ms" << endl;
			// output
			fstream fout(argv[3], ios::out);
		   	for (int i = 0; i < DataNumber; i++) {
		   		fout << Data[i] << endl;
		   	}
		}
		else if (type == "double") {
			// input
			vector<double> Data;
			double tmp;
			for (int i = 0; i < DataNumber; i++) {
				finput >> tmp;
				Data.push_back(tmp);
			}

			double START, END; 
			START = clock();
			// sort
			SortingTool SortingTool; // Constructor
			if (!strcmp(argv[1],"-SS")) SortingTool.selectionsort(Data.data(), Data.size(), sizeof(double), SortingTool.compareDouble);
			else if (!strcmp(argv[1],"-IS")) SortingTool.insertionsort(Data.data(), Data.size(), sizeof(double), SortingTool.compareDouble);
			else if (!strcmp(argv[1],"-BS")) SortingTool.bubblesort(Data.data(), Data.size(), sizeof(double), SortingTool.compareDouble);

			END = clock();
	    	cout <<"The total CPU time: " << (END - START) << " ms" << endl;
			// output
			fstream fout(argv[3], ios::out);
		   	for (int i = 0; i < DataNumber; i++) {
		   		fout << Data[i] << endl;
		   	}
		}

		
	}
    
}
