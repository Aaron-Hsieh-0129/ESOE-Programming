#include <iostream>
#include <fstream>
#include <time.h>
#include <vector>
#include <random>
#include <cstring>

using namespace std;
void help_message(){
	cout << "./NormalDataGenerate <data number> <output>" << endl;
	cout << "Ex: ./NormalDataGenerate 1000 ../generated_data/data_normal_generated/1000" << endl;
	
}

bool mycompare(int a, int b) {
    return a > b;
}

bool mycompare2(double a, double b) {
    return a > b;
}

int random_index(int minnum, int maxnum) {
	struct timespec time1 = { 0, 0 };
	clock_gettime(CLOCK_REALTIME, &time1);
	srand(time1.tv_nsec);
	int choice = maxnum - minnum + 1;
	int a = rand() % choice + minnum;
	return a;
}

int main(int argc, char* argv[]) {
	if (argc != 3) {
		help_message();
		return 0;
	}

	// generate int
	string file1 = (string) argv[2] + "_int_random.txt";
	fstream fout(file1, ios::out);

	vector<int> data1;
	random_device rd1;
    default_random_engine eng1(rd1());
    uniform_int_distribution<> distr1(-1e8, 1e8);

	int DataNumber = stoi(argv[1]);
	for (int j = 0; j < DataNumber; j++) {
        data1.push_back(distr1(eng1));
    }

    fout << "int" << endl;
    fout << DataNumber << endl;
    for (int i = 0; i < DataNumber; i++) {
        fout << data1[i] << "\n";
    }

    // increasing
    string file1_inc = (string) argv[2] + "_int_increasing.txt";
    fstream fout1_inc(file1_inc, ios::out);
    vector<int> data_inc;
    data_inc.assign(data1.begin(), data1.end());
    sort(data_inc.begin(), data_inc.end());
    fout1_inc << "int" << endl;
    fout1_inc << DataNumber << endl;
    for (int i = 0; i < DataNumber; i++) {
        fout1_inc << data_inc[i] << "\n";
    }

    // decreasing
    string file1_dec = (string) argv[2] + "_int_decreasing.txt";
    fstream fout1_dec(file1_dec, ios::out);
    vector<int> data_dec;
    data_dec.assign(data1.begin(), data1.end());
    sort(data_dec.begin(), data_dec.end(), mycompare);
    fout1_dec << "int" << endl;
    fout1_dec << DataNumber << endl;
    for (int i = 0; i < DataNumber; i++) {
        fout1_dec << data_dec[i] << "\n";
    }

    // semi
    string file1_semi = (string) argv[2] + "_int_semi.txt";
    fstream fout1_semi(file1_semi, ios::out);

    int a = 0;
    random_device rd3;
    default_random_engine eng3(rd3());
    uniform_int_distribution<> distr3(0, DataNumber-1);
    for (int j = 0; j < DataNumber; j++) {
        a = distr3(eng3);
        if (a % 10 == 0) {
            swap(data_inc[j], data_inc[a % DataNumber]);
        }
    }
    fout1_semi << "int" << endl;
    fout1_semi << DataNumber << endl;
    for (int i = 0; i < DataNumber; i++) {
        fout1_semi << data_inc[i] << "\n";
    }


   
    // generate float
    string file2 = (string) argv[2] + "_real_random.txt";
    fstream foutReal(file2, ios::out);
	random_device rd2;
    default_random_engine eng2(rd2());
    uniform_real_distribution<double> distr2(-1e8, 1e8);

    vector<double> data2;

    for (int j = 0; j < DataNumber; j++) {
        data2.push_back(distr2(eng2));
    }

    foutReal << "double" << endl;
    foutReal << DataNumber << endl;
	for (int n = 0; n < DataNumber; n++) {
        foutReal << data2[n] << "\n";
    }

    // increasing
    string file2_inc = (string) argv[2] + "_real_increasing.txt";
    fstream fout2_inc(file2_inc, ios::out);
    vector<double> data2_inc;
    data2_inc.assign(data2.begin(), data2.end());
    sort(data2_inc.begin(), data2_inc.end());

    fout2_inc << "double" << endl;
    fout2_inc << DataNumber << endl;
    for (int i = 0; i < DataNumber; i++) {
        fout2_inc << data2_inc[i] << "\n";
    }

    // decreasing
    string file2_dec = (string) argv[2] + "_real_decreasing.txt";
    fstream fout2_dec(file2_dec, ios::out);
    vector<double> data2_dec;
    data2_dec.assign(data2.begin(), data2.end());

    sort(data2_dec.begin(), data2_dec.end(), mycompare2);
    fout2_dec << "double" << endl;
    fout2_dec << DataNumber << endl;
    for (int i = 0; i < DataNumber; i++) {
        fout2_dec << data2_dec[i] << "\n";
    }

    // semi
    string file2_semi = (string) argv[2] + "_real_semi.txt";
    fstream fout2_semi(file2_semi, ios::out);

    int b = 0;
    random_device rd5;
    default_random_engine eng5(rd5());
    uniform_int_distribution<> distr5(0, DataNumber-1);
    for (int j = 0; j < DataNumber; j++) {
        b = distr5(eng5);
        if (b % 10 == 0) {
            swap(data2_inc[j], data2_inc[b % DataNumber]);
        }
    }

    fout2_semi << "double" << endl;
    fout2_semi << DataNumber << endl;
    for (int i = 0; i < DataNumber; i++) {
        fout2_semi << data2_inc[i] << endl;
    }

    return 0;
}