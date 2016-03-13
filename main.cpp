#include <iostream>
#include "reader.cpp"




using namespace std;

int main(){

    SyllableReader::Reader::add("/Users/Mistral/ClionProjects/SyllableReader/SyllableDB-V1.dat");

    SyllableReader::Reader::read("/Users/Mistral/Downloads/textInput1000W_v2.txt");

    SyllableReader::Reader::search();




}

