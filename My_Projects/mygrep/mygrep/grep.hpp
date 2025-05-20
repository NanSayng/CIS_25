//
//  grep.hpp
//  grep_Project
//
//  Created by Nan Sayng on 5/20/25.
//

#ifndef grep_hpp
#define grep_hpp
#include <fstream>
#include <string>
#include <iostream>

/* features */
void readTxtFile(const std::string& filename, const std::string& keyword, bool caseInsensitive, bool showLineNum);
bool matchString(const std::string& line, const std::string& givenStr, bool caseInsensitive);
std::string toLowerStr(const std::string& str);
#endif /* grep_hpp */
