#include <iostream>
#include <fstream>
#include <string>
#include "grep.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    string filename, keyword;
    
    bool caseInsensitive = false;
    bool showLineNum = false;
    
    if(argc < 3 || argc > 5){
        cout << "Usage: ./mygrep [-i] [-n] <keyword> <filename>\n";
        return 1;
    }else {
        if(argc == 5){
            keyword = argv[3];
            filename = argv[4];
            string flag1 = string(argv[1]);
            string flag2 = string(argv[2]);
            if(flag1 == "-i" && flag2 == "-n" || flag1 == "-n" && flag2 == "-i"){
                caseInsensitive = true;
                showLineNum = true;
            }else {
                cout << "Invalid flags.\n";
                return 1;
            }
            readTxtFile(filename, keyword, caseInsensitive, showLineNum);
        }else if(argc == 4){
            keyword = argv[2];
            filename = argv[3];
            if(string(argv[1]) == "-i"){
                caseInsensitive = true;
            }else{
                showLineNum = true;
            }
            readTxtFile(filename, keyword, caseInsensitive, showLineNum);
        }else {
            keyword = argv[1];
            filename = argv[2];
            readTxtFile(filename, keyword, caseInsensitive, showLineNum);
        }
    }
    
    return 0;
}
