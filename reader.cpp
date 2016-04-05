//
// Created by JM on 2/18/2016 AD.
//


#include "reader.h"



using namespace std;

namespace SyllableReader{

    vector<string> Reader::db;
    vector<string> Reader::readedFile;
    unordered_map<std::string,int> Reader::hashmap;


    void Reader::add(string path)
    {
        ifstream fp(path, ios::binary);
        FILEID id;
        int runner = 1;


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

            std::pair<std::string,int> element (out,runner);
            hashmap.insert(element);
            runner++;

        }
    }
    void Reader::read(string path){

        ifstream file;
        string cache;
        string conversion;

        char cacheArray[1000];

        char text1[100];
        char text2[100];
        char text3[100];
        char text4[100];



        file.open(path);
        while(getline(file,cache)){
            strncpy(cacheArray, cache.c_str(), sizeof(cacheArray));
            sscanf(cacheArray,"%s %s %s %s ",text1,text2,text3,text4);
            conversion = string(text4);
            readedFile.push_back(conversion);
        }

    }
    void Reader::search()
    {
        FILE *f = fopen("/Users/Mistral/ClionProjects/SyllableReaderProj/file.txt", "w");

        clock_t start,end;
        double elapsed_time;

        int count = 1;
        int founded = 1;
        char outchar[200];

        start = clock();
        /*for(string keyword : readedFile) {
            founded = 1;
            count = 1;
            for(string out: db) {
                if (out == keyword) {
                    fprintf(f, "Founded at ID: %d, Text: %s \n", count, out.c_str());
                    printf("Founded at ID: %d, Text: %s \n", count, out.c_str());
                    founded = 0;
                }
                count++;
            }
            if(founded == 1){
                fprintf(f ,"Not Founded \n");
                printf("Not Founded \n");
            }
        }*/
        for(string keyword : readedFile) {
            founded = 1;
            count = 1;

            std::unordered_map<std::string,int>::const_iterator got = hashmap.find (keyword);
            if ( got == hashmap.end() ) {
                fprintf(f, "Not Founded \n");
                std::cout << "not found";
            }
            else {
                std::cout << got->first << " is " << got->second;
                fprintf(f, "Founded at ID: %d, Text: %s \n", got->second, (got->first).c_str());
            }
            std::cout << std::endl;
        }
        end = clock();
        elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
        fprintf(f,"Elapsed time = %lf\n",elapsed_time);
        printf("Elapsed time = %lf\n",elapsed_time);


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