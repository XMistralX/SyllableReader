#include <iostream>
#include "reader.cpp"

using namespace std;

int main(){

    SyllableReader::Reader::add("/Users/Mistral/ClionProjects/SyllableReader/SyllableDB-V1.dat");
    SyllableReader::Reader::print();
    SyllableReader::Reader::count();

}