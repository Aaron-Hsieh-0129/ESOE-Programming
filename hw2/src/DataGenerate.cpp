#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

int main(void){
    /////////////////    Generate firstname from data_dictionary      /////////////
    char buffer1[200];
	fstream fin1("../data_dictionary/firstnamedict.txt");
    fstream fout1("../data_generated/firstnamelist.txt", ios::out);

    fin1.getline(buffer1, 200);
    vector<string> data1;
    string tmp1;
    while (fin1 >> tmp1){
    	data1.push_back(tmp1);
    }
    
    srand(time(NULL));
    int index1[100];
    for(int i = 0 ; i < 100 ;i++){
        index1[i] = rand();
        index1[i] = index1[i] % data1.size();
    }

    for (int j = 0; j < 100; j++){
        fout1 << data1[index1[j]] << endl;
    }

    fin1.close();
    fout1.close();
    
    /////////////////    Generate lastname from data_dictionary      /////////////
    char buffer2[200];
    fstream fin2("../data_dictionary/lastnamedict.txt");
    fstream fout2("../data_generated/lastnamelist.txt", ios::out);

    fin2.getline(buffer2, 200);
    vector<string> data2;
    string tmp2;
    while (fin2 >> tmp2){
        data2.push_back(tmp2);
    }
    
    srand(time(NULL));
    int index2[100];
    for(int i = 0 ; i < 100 ;i++){
        index2[i] = rand();
        index2[i] = index2[i] % data2.size();
    }

    for (int j = 0; j < 100; j++){
        fout2 << data2[index2[j]] << endl;
    }

    fin2.close();
    fout2.close();
    

    /////////////////    Generate score      /////////////
    fstream fout3("../data_generated/scorelist.txt", ios::out);
    srand(time(NULL));
    int index3[100];
    for(int i = 0 ; i < 100 ;i++){
        index3[i] = rand();
        index3[i] = index3[i] % 100;
    }
    for (int j = 0; j < 100; j++){
        fout3 << index3[j] << endl;
    }
    fout3.close();

    /////////////////    Generate ID      /////////////
    fstream fout4("../data_generated/ID.txt", ios::out);
    srand(time(NULL));
    int index4[100];
    for(int i = 0 ; i < 100 ;i++){
        index4[i] = rand();
        index4[i] = index4[i] % 10000000;
    }
    for (int j = 0; j < 100; j++){
        fout4 << index4[j] << endl;
    }
    fout4.close();

    return 0;
}