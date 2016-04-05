//
// Created by JM on 2/18/2016 AD.
//

#ifndef SYLLABLEREADERPROJ_READER_H
#define SYLLABLEREADERPROJ_READER_H
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "iconv.h"
#include <unordered_map>
#include <string>


#define FILEID_SIZE (256)
#define MAX_SYLLABLE_TEXTSIZE (1023)

using namespace std;

namespace SyllableReader{
    typedef union _fileid_un
    {
        struct fileid_crack_st
        {
            uint16_t ui16MagicKey;
            uint16_t ui16Type;
            uint16_t ui16EntrySize;
            uint16_t _filler;
            uint32_t ui32NumEntry;
            time_t tTimeStamp;
        }crack;
        char szRaw[FILEID_SIZE];
    }FILEID;

    typedef struct syllable_data_record_st
    {
        uint32_t ui32SylID;
        uint16_t ui2Lang:2;
        uint16_t ui10Len:10;
        uint16_t ui1HasTailSpace:1;
        uint16_t ui1IsUnused:1;
        uint16_t ui1Numeric:1;
        uint16_t _filler:1;
        uint32_t ui32MapFilePos;
        time_t tTimeStamp;
        char szText[MAX_SYLLABLE_TEXTSIZE];
    }SYLLABLE_DATA_RECORD;
    class Reader
    {

    public:
        static std::vector<string> db;
        static std::vector<string> readedFile;
        static std::unordered_map<std::string,int> hashmap;
        static void add(string path);
        static void read(string path);
        static void search();
        static void count();
        static void print();
    };
}


#endif //SYLLABLEREADERPROJ_READER_H
