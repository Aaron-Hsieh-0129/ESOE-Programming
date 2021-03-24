#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <fstream>


using namespace std;

typedef struct{
        string firstName;
        string lastName;
        int ID;
        size_t score;
}Student;



void selectionsort(void *const base, size_t num, size_t size, int (*compar) (const void*, const void*)) {
	char *base_ptr = (char *) base;
	void *tmp = malloc(size);
	int min_index = 0;
	for (int i = 0; i < num - 1; i++) {
		min_index = i;
		for (int j = i + 1; j < num; j++) {
			if ((*compar) ((void *) (base_ptr + size * min_index), (void *) (base_ptr + size * j)) > 0) {
				min_index = j;
			}
		}
		memcpy(tmp, base_ptr + size * min_index, size);
		memcpy(base_ptr + size * min_index, base_ptr + size * i, size);
		memcpy(base_ptr + size * i, tmp, size);
	}
	return;
}


void insertionsort(void *const base, size_t num, size_t size, int (*compar) (const void*, const void*)) {
	char *base_ptr = (char *) base;
	char *now;
	void *tmp = malloc(size);
	for (int j = 1; j < num; j++) {
		memcpy(tmp, base_ptr + j * size, size);
		int i = j - 1;
		while (i >= 0 && (*compar) ((void *) (base_ptr + i * size), (void *) tmp) > 0) {
			memcpy(base_ptr + (i + 1) * size, base_ptr + i * size, size);
			i--;
		}
		memcpy(base_ptr + (i + 1) * size, tmp, size);

	}
	free(tmp);
	return;
}


void bubblesort(void *const base, size_t num, size_t size, int (*compar) (const void*, const void*)) {
	char *base_ptr = (char *) base;
	int i = num;
	void *tmp = malloc(size);
	while (i > 0) {
		for (int j = 0; j < i - 1; j++) {
			if ((*compar) ((void *) (base_ptr + j * size), (void *) (base_ptr + (j + 1) * size)) > 0) {
				memcpy(tmp, base_ptr + j * size, size);
				memcpy(base_ptr + j * size, base_ptr + (j + 1) * size, size);
				memcpy(base_ptr + (j + 1) * size, tmp, size);
			}
		}
		i--;
	}
	return;
}


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
	cout << "usage: ./Sorting -[Score|ID|FirstName|LastName] -[SS|IS|BS] <output_file>" << endl;
}

int main(int argc, char* argv[]){
	if (argc != 4){
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
		if (!strcmp(argv[2],"-SS")) selectionsort(Class.data(), Class.size(), sizeof(Student), compareScore);
		else if (!strcmp(argv[2],"-IS")) insertionsort(Class.data(), Class.size(), sizeof(Student), compareScore);
		else if (!strcmp(argv[2],"-BS")) bubblesort(Class.data(), Class.size(), sizeof(Student), compareScore);
    }
    else if(!strcmp(argv[1],"-ID")){
        if (!strcmp(argv[2],"-SS")) selectionsort(Class.data(), Class.size(), sizeof(Student), compareID);
		else if (!strcmp(argv[2],"-IS")) insertionsort(Class.data(), Class.size(), sizeof(Student), compareID);
		else if (!strcmp(argv[2],"-BS")) bubblesort(Class.data(), Class.size(), sizeof(Student), compareID);
    }
    else if(!strcmp(argv[1], "-FirstName")){
    	if (!strcmp(argv[2],"-SS")) selectionsort(Class.data(), Class.size(), sizeof(Student), compareFirstName);
		else if (!strcmp(argv[2],"-IS")) insertionsort(Class.data(), Class.size(), sizeof(Student), compareFirstName);
		else if (!strcmp(argv[2],"-BS")) bubblesort(Class.data(), Class.size(), sizeof(Student), compareFirstName);
    }
    else if(!strcmp(argv[1],"-LastName")){
        if (!strcmp(argv[2],"-SS")) selectionsort(Class.data(), Class.size(), sizeof(Student), compareLastName);
		else if (!strcmp(argv[2],"-IS")) insertionsort(Class.data(), Class.size(), sizeof(Student), compareLastName);
		else if (!strcmp(argv[2],"-BS")) bubblesort(Class.data(), Class.size(), sizeof(Student), compareLastName);
    }
    else {
        help_message();
        return 0;
    }
    //////////// write the output file ///////////
    fstream fout(argv[3], ios::out);
    fout << "     ID" << "      FirstName" << "          LastName" << "     Score" << endl;
    for (int i = 0; i < 100; i++){
        fout << setw(8) << Class[i].ID << "      " << setw(10) << Class[i].firstName << setw(16) << Class[i].lastName << setw(10) << Class[i].score << endl;
        
    }
    return 0;
}
