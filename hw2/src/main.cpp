#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <cstring>


using namespace std;

typedef struct{
        string firstName;
        string lastName;
        int ID;
        size_t score;
}Student;

int compareScore(const void * a, const void * b){
	Student *pa=(Student *)a;
	Student *pb=(Student *)b;
	return (pa->score - pb->score);
}

int compareID(const void * a, const void * b){
	Student *pa=(Student *)a;
	Student *pb=(Student *)b;
	return (pa->ID - pb->ID);
}

int compareFirstName(const void * a, const void * b){
	Student *pa=(Student *)a;
	Student *pb=(Student *)b;
	string A = pa->firstName;
	string B = pb->firstName;
	return strcmp(A.c_str(), B.c_str());
}

int compareLastName(const void * a, const void * b){
	Student *pa=(Student *)a;
	Student *pb=(Student *)b;
	string A = pa->lastName;
	string B = pb->lastName;
	return strcmp(A.c_str(), B.c_str());
}

void help_message(){
	cout << "usage: ./Sorting -[Score|ID|FirstName|LastName] <output_file>" << endl;
}

int main(int argc, char* argv[]){
	if (argc != 3){
		help_message();
		return 0;
	}
	//////////// read the input file /////////////
	vector<Student> Class(100);
	string tmpFirst, tmpLast;
	int tmpScore, tmpID;
	fstream fFirst("../data_generated/firstnamelist.txt");
	for (int i = 0; i < 100; i++){
		fFirst >> tmpFirst;
		Class[i].firstName = tmpFirst;
	}
	fstream fLast("../data_generated/lastnamelist.txt");
	for (int i = 0; i < 100; i++){
		fLast >> tmpLast;
		Class[i].lastName = tmpLast;
	}

	fstream fScore("../data_generated/scorelist.txt");
	for (int i = 0; i < 100; i++){
		fScore >> tmpScore;
		Class[i].score = tmpScore;
	}

	fstream fID("../data_generated/ID.txt");
	for (int i = 0; i < 100; i++){
		fID >> tmpID;
		Class[i].ID = tmpID;
	}

	//////////// the sorting part ////////////////
	if(!strcmp(argv[1],"-Score")){
        qsort(Class.data(), Class.size(), sizeof(Student), compareScore);
    }
    else if(!strcmp(argv[1],"-ID")){
        qsort(Class.data(), Class.size(), sizeof(Student), compareID);
    }
    else if(!strcmp(argv[1], "-FirstName")){
    	qsort(Class.data(), Class.size(), sizeof(Student), compareFirstName);
    }
    else if(!strcmp(argv[1],"-LastName")){
        qsort(Class.data(), Class.size(), sizeof(Student), compareLastName);
    }
    else {
        help_message();
        return 0;
    }
    //////////// write the output file ///////////
    fstream fout(argv[2], ios::out);
    fout << "     ID" << "      FirstName" << "          LastName" << "     Score" << endl;
    for (int i = 0; i < 100; i++){
        fout << setw(8) << Class[i].ID << "      " << setw(10) << Class[i].firstName << setw(16) << Class[i].lastName << setw(10) << Class[i].score << endl;
        
    }

}