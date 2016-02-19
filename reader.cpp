//
// Created by JM on 2/18/2016 AD.
//


#include "reader.h"


using namespace std;

namespace SyllableReader{

    vector<string> Reader::db;

    void Reader::add(string path)
    {
        ifstream fp(path, ios::binary);
        FILEID id;


        char out[1023];

        fp.read((char*) &id, sizeof(id));
        while(true){
            SYLLABLE_DATA_RECORD entry;
            char *input = &entry.szText[0];
            char out[1023];
            char *output = &out[0];

            fp.read((char*) &entry, sizeof(entry) - MAX_SYLLABLE_TEXTSIZE - 1);
            if(!fp){
                break;
            }
            fp.getline((char*) &entry.szText, MAX_SYLLABLE_TEXTSIZE, 0);
            iconv_t charset = iconv_open("UTF8", "CP874");
            size_t inLeft = 1023;
            size_t outLeft = 1023;

            iconv(charset, &input, &inLeft, &output, &outLeft);

            db.push_back(out);



        }
    }
    void Reader::count()
    {
        printf("Array size is:%d",db.size());
    }
    void Reader::print()
    {
        int count = 1;
        for(string out : db) {
            printf("id: %d entry: %s\n",count,out.c_str());
            count++;
        }
    }
}