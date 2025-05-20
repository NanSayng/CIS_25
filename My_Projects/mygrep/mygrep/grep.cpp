//
//  grep.cpp
//  grep_Project
//
//  Created by Nan Sayng on 5/20/25.
//

#include "grep.hpp"
using namespace std;

string toLowerStr(const string& str){
    string lowerStr  = str;
    for(char& c : lowerStr){
        c = tolower(c);
    }
    return lowerStr;
}

bool matchString(const std::string& line, const std::string& givenStr, bool caseInsensitive){
    if(caseInsensitive){
        string lowerLine = toLowerStr(line);
        string lowerStr = toLowerStr(givenStr);
        return (lowerLine.find(lowerStr) != string::npos);
    }
    return (line.find(givenStr) != string::npos);
}

void readTxtFile(const string& filename, const string& keyword, bool caseInsensitive, bool showLineNum){
    ifstream file(filename); // open file to read
    if(!file.is_open()){
        cout << "Error opening the file.\n";
        return;
    }
    string line;
    int countLine = 0;
    while(getline(file, line)){
        countLine++;
        if(matchString(line, keyword, caseInsensitive)){
            if(showLineNum){
                cout << "Line " << countLine << ": " << line << endl;
            }else{
                cout << line << endl;
            }
        }
    }
    file.close();  // close file after reading
}




