#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>

void CountWords(char * ifname, char * ofname = nullptr);


int main(int argc, char ** argv) {
    if(argc<2) {
        std::cout<<"File not specified\n";
    }
    else
    {
        if(argc>2) {
            CountWords(argv[1], argv[2]);
        }
        else {
            CountWords(argv[1]);
        }
    }
    return 0;
}

typedef struct WordCnt {
    std::string word;
    size_t cnt = 0;
} WordCnt;

void CountWords(char * ifname, char * ofname) {
    std::vector<WordCnt> words;
    if(ifname==nullptr)return;
    try {
        std::ifstream ifile;
        ifile.open(ifname);
        std::string word;
        bool filling = false;
        while (ifile.eof()==false) {
            char c;
            ifile>>c;
            if(isalpha(c)) {
                filling = true;
                word.push_back(c);
            }
            else {
                if(filling) {
                    size_t i = 0, len = words.size();
                    bool success= false;
                    while(i<len) {
                        if(words[i].word==word) {
                            words[i].cnt++;
                            success = true;
                            break;
                        }
                        i++;
                    }
                    if(!success) {
                        WordCnt wc;
                        wc.word = word;
                        wc.cnt = 1;
                        words.push_back(wc);
                    }
                    word.clear();
                }
                filling = 0;
                
                
            }
        }
    }
    catch (...) {

    }
    {
        size_t i = 0, len = words.size();
        //bool success= false;
        while(i<len) {
            std::cout<<"\""<<words[i].word<<"\""<<"\t:\t"<<words[i].cnt<<" pcs\n";
            i++;
        }
    }
    if(ofname!=nullptr){
		try{
			std::ofstream ofile;
			ofile.open(ofname);
			size_t i = 0, len = words.size();
        //bool success= false;
        while(i<len) {
            ofile<<"\""<<words[i].word<<"\""<<"\t: "<<words[i].cnt<<" pcs\n";
            i++;
        }
		}
		catch(...){
			
		}
	}


}

