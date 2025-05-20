//
//  grep.cpp
//  grep_Project
//
//  Created by Nan Sayng on 5/20/25.
//

#include "grep.hpp"
using namespace std;

// converts string to lower case - used for caseInsenstive case
string toLowerStr(const string& str){
    string lowerStr  = str;
    for(char& c : lowerStr){
        c = tolower(c); // convert each character to lower case
    }
    return lowerStr; // return converted lower-cased string
}

// Checks if the given keyword exists in the line (case-sensitive or case-insensitive)
bool matchString(const std::string& line, const std::string& givenStr, bool caseInsensitive){
    if(caseInsensitive){
        string lowerLine = toLowerStr(line);
        string lowerStr = toLowerStr(givenStr);
        return (lowerLine.find(lowerStr) != string::npos); // check if keyword is in the line (caseInsensitive)
    }
    return (line.find(givenStr) != string::npos);  // check if keyword is in the line (caseSensitive)
}

// Reads the text file line-by-line, checks for matches, and prints matching lines
void readTxtFile(const string& filename, const string& keyword, bool caseInsensitive, bool showLineNum){
    ifstream file(filename); // open file to read
    if(!file.is_open()){ // check if file is opened successfully
        cout << "Error opening the file.\n";
        return;
    }
    string line;
    int countLine = 0; // to count the line number
    while(getline(file, line)){
        countLine++;
        if(matchString(line, keyword, caseInsensitive)){ // if each line contain keyword
            if(showLineNum){
                cout << "Line " << countLine << ": " << line << endl; // print with line number
            }else{
                cout << line << endl;  // print without line number
            }
        }
    }
    file.close();  // close file after reading
}




