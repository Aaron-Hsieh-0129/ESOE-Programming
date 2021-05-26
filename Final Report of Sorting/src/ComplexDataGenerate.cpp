#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cstring>
#include <random>
#include <algorithm>

using namespace std;

int DataNumber;

void help_message() {
    cout << "usage: ./DataGenerate <data number>" << endl;
    cout << "Ex: ./DataGenerate 1000" << endl;
}

bool mycompare(string a, string b) {
    return a > b;
}

bool mycompare2(int a, int b) {
    return a > b;
}

void Increasing(string inputName, string outputName, int DataNum);
void IncreasingNum(string inputName, string outputName, int DataNum);
void Decreasing(string inputName, string outputName, int DataNum);
void DecreasingNum(string inputName, string outputName, int DataNum);
void Semi(string inputName, string outputName, int DataNum);
void SemiNum(string inputName, string outputName, int DataNum);


int main(int argc, char *argv[]){
    if (argc != 2){
        help_message();
        return 0;
    }

    DataNumber = stoi(argv[1]);

    /////////////////    Generate firstname from data_dictionary      /////////////
    char buffer1[DataNumber*10];
	fstream fin1("../data_dictionary/firstnamedict.txt");

    string root = "../generated_data/data_complex_generated/";
    string filename = to_string(DataNumber) + "_firstnamelist_Random.txt";
    string outname = root + filename;
    fstream fout1(outname, ios::out);
    fin1.getline(buffer1, DataNumber*10);
    vector<string> data1;
    string tmp1;

    while (fin1 >> tmp1){
    	data1.push_back(tmp1);
    }

    random_device rd1;
    default_random_engine eng1(rd1());
    uniform_int_distribution<> distr1(0, data1.size()-1);

    srand(time(NULL));
    int index1[DataNumber];
    for(int i = 0 ; i < DataNumber ;i++){
        index1[i] = distr1(eng1);
    }

    fout1 << DataNumber << endl;
    for (int j = 0; j < DataNumber; j++){
        fout1 << data1[index1[j]] << endl;
    }

    fin1.close();
    fout1.close();
    
    /////////////////    Generate lastname from data_dictionary      /////////////
    char buffer2[DataNumber*10];
    fstream fin2("../data_dictionary/lastnamedict.txt");
    string root2 = "../generated_data/data_complex_generated/";
    string filename2 = to_string(DataNumber) + "_lastnamelist_Random.txt";
    string outname2 = root2 + filename2;
    fstream fout2(outname2, ios::out);

    fin2.getline(buffer2, DataNumber*10);
    vector<string> data2;
    string tmp2;
    while (fin2 >> tmp2){
        data2.push_back(tmp2);
    }
    
    random_device rd2;
    default_random_engine eng2(rd2());
    uniform_int_distribution<> distr2(0, data2.size()-1);
    int index2[DataNumber];
    for(int i = 0 ; i < DataNumber ;i++){
        index2[i] = distr2(eng1);
    }

    fout2 << DataNumber << endl;
    for (int j = 0; j < DataNumber; j++){
        fout2 << data2[index2[j]] << endl;
    }

    fin2.close();
    fout2.close();
    

    /////////////////    Generate score      /////////////
    string root3 = "../generated_data/data_complex_generated/";
    string filename3 = to_string(DataNumber) + "_scorelist_Random.txt";
    string outname3 = root3 + filename3;
    fstream fout3(outname3, ios::out);
    
    random_device rd3;
    default_random_engine eng3(rd3());
    uniform_int_distribution<> distr3(0, 100);
    int index3[DataNumber];
    for(int i = 0 ; i < DataNumber ;i++){
        index3[i] = distr3(eng3);
    }

    fout3 << DataNumber << endl;
    for (int j = 0; j < DataNumber; j++){
        fout3 << index3[j] << endl;
    }
    fout3.close();

    /////////////////    Generate ID      /////////////
    string root4 = "../generated_data/data_complex_generated/";
    string filename4 = to_string(DataNumber) + "_ID_Random.txt";
    string outname4 = root3 + filename4;
    fstream fout4(outname4, ios::out);
    
    random_device rd4;
    default_random_engine eng4(rd4());
    uniform_int_distribution<> distr4(0, 10000000);
    int index4[DataNumber];
    for(int i = 0 ; i < DataNumber ;i++){
        index4[i] = distr4(eng4) % 10000000;
    }

    fout4 << DataNumber << endl;
    for (int j = 0; j < DataNumber; j++){
        fout4 << index4[j] << endl;
    }
    fout4.close();

    /*
    Generate different order data
    */
    /////////// Increasing ///////////
    string outroot = "../generated_data/data_complex_generated/";
    string filenameOut1 = to_string(DataNumber) + "_firstnamelist_Increasing.txt";
    string total1 = outroot + filenameOut1;

    string filenameOut2 = to_string(DataNumber) + "_lastnamelist_Increasing.txt";
    string total2 = outroot + filenameOut2;

    string filenameOut4 = to_string(DataNumber) + "_ID_Increasing.txt";
    string total4 = outroot + filenameOut4;

    string filenameOut3 = to_string(DataNumber) + "_scorelist_Increasing.txt";
    string total3 = outroot + filenameOut3;
    
    Increasing(outname, total1, DataNumber);
    Increasing(outname2, total2, DataNumber);
    IncreasingNum(outname4, total4, DataNumber);
    IncreasingNum(outname3, total3, DataNumber);

    /////////// Decreasing ///////////
    string filenameOut21 = to_string(DataNumber) + "_firstnamelist_Decreasing.txt";
    string total21 = outroot + filenameOut21;

    string filenameOut22 = to_string(DataNumber) + "_lastnamelist_Decreasing.txt";
    string total22 = outroot + filenameOut22;

    string filenameOut24 = to_string(DataNumber) + "_ID_Decreasing.txt";
    string total24 = outroot + filenameOut24;

    string filenameOut23 = to_string(DataNumber) + "_scorelist_Decreasing.txt";
    string total23 = outroot + filenameOut23;

    Decreasing(outname, total21, DataNumber);
    Decreasing(outname2, total22, DataNumber);
    DecreasingNum(outname4, total24, DataNumber);
    DecreasingNum(outname3, total23, DataNumber);

    // semi
    string filenameOut31 = to_string(DataNumber) + "_firstnamelist_Semi.txt";
    string total31 = outroot + filenameOut31;

    string filenameOut32 = to_string(DataNumber) + "_lastnamelist_Semi.txt";
    string total32 = outroot + filenameOut32;

    string filenameOut34 = to_string(DataNumber) + "_ID_Semi.txt";
    string total34 = outroot + filenameOut34;

    string filenameOut33 = to_string(DataNumber) + "_scorelist_Semi.txt";
    string total33 = outroot + filenameOut33;

    Semi(outname, total31, DataNumber);
    Semi(outname2, total32, DataNumber);
    SemiNum(outname4, total34, DataNumber);
    SemiNum(outname3, total33, DataNumber);
    return 0;
}

void Increasing(string inputName, string outputName, int DataNum) {
    char buffer[DataNum*10];
    fstream finInc(inputName);
    fstream foutInc(outputName, ios::out);

    finInc.getline(buffer, DataNum*10);
    vector<string> dataInc;
    string tmpInc;
    while (finInc >> tmpInc){
        dataInc.push_back(tmpInc);
    }
    
    
    foutInc << DataNum << endl;
    sort(dataInc.begin(), dataInc.end());
    for (int j = 0; j < DataNum; j++) {
        foutInc << dataInc[j] << endl;
    }

    finInc.close();
    foutInc.close();
}

void IncreasingNum(string inputName, string outputName, int DataNum) {
    char buffer[DataNum*10];
    fstream finInc(inputName);
    fstream foutInc(outputName, ios::out);

    finInc.getline(buffer, DataNum*10);
    vector<int> dataInc;
    int tmpInc;
    while (finInc >> tmpInc){
        dataInc.push_back(tmpInc);
    }
    
    
    foutInc << DataNum << endl;
    sort(dataInc.begin(), dataInc.end());
    for (int j = 0; j < DataNum; j++) {
        foutInc << dataInc[j] << endl;
    }

    finInc.close();
    foutInc.close();
}

void Decreasing(string inputName, string outputName, int DataNum) {
    char buffer[DataNum*10];
    fstream finInc(inputName);
    fstream foutInc(outputName, ios::out);

    finInc.getline(buffer, DataNum*10);
    vector<string> dataInc;
    string tmpInc;
    while (finInc >> tmpInc){
        dataInc.push_back(tmpInc);
    }
    
    
    foutInc << DataNum << endl;
    sort(dataInc.begin(), dataInc.end(), mycompare);
    for (int j = 0; j < DataNum; j++) {
        foutInc << dataInc[j] << endl;
    }

    finInc.close();
    foutInc.close();
}

void DecreasingNum(string inputName, string outputName, int DataNum) {
    char buffer[DataNum*10];
    fstream finInc(inputName);
    fstream foutInc(outputName, ios::out);

    finInc.getline(buffer, DataNum*10);
    vector<int> dataInc;
    int tmpInc;
    while (finInc >> tmpInc){
        dataInc.push_back(tmpInc);
    }
    
    
    foutInc << DataNum << endl;
    sort(dataInc.begin(), dataInc.end(), mycompare2);
    for (int j = 0; j < DataNum; j++) {
        foutInc << dataInc[j] << endl;
    }

    finInc.close();
    foutInc.close();
}

void Semi(string inputName, string outputName, int DataNum) {
    char buffer[DataNum*10];
    fstream finInc(inputName);
    fstream foutInc(outputName, ios::out);

    finInc.getline(buffer, DataNum*10);
    vector<string> dataInc;
    string tmpInc;
    while (finInc >> tmpInc){
        dataInc.push_back(tmpInc);
    }
    
    
    foutInc << DataNum << endl;
    sort(dataInc.begin(), dataInc.end());
    int a = 0;
    random_device rd1;
    default_random_engine eng1(rd1());
    uniform_int_distribution<> distr1(0, DataNum-1);

    for (int j = 0; j < DataNum; j++) {
        a = distr1(eng1);
        if (a % 10 == 0) {
            swap(dataInc[j], dataInc[a % DataNum]);
        }
    }

    for (int j = 0; j < DataNum; j++) {
        foutInc << dataInc[j] << endl;
    }

    finInc.close();
    foutInc.close();
}

void SemiNum(string inputName, string outputName, int DataNum) {
    char buffer[DataNum*10];
    fstream finInc(inputName);
    fstream foutInc(outputName, ios::out);

    finInc.getline(buffer, DataNum*10);
    vector<int> dataInc;
    int tmpInc;
    while (finInc >> tmpInc){
        dataInc.push_back(tmpInc);
    }
    
    
    foutInc << DataNum << endl;
    sort(dataInc.begin(), dataInc.end());

    int a = 0;
    random_device rd1;
    default_random_engine eng1(rd1());
    uniform_int_distribution<> distr1(0, DataNum-1);
    for (int j = 0; j < DataNum; j++) {
        a = distr1(eng1);
        if (a % 10 == 0) {
            swap(dataInc[j], dataInc[a % DataNum]);
        }
    }

    for (int j = 0; j < DataNum; j++) {
        foutInc << dataInc[j] << endl;
    }

    finInc.close();
    foutInc.close();
}