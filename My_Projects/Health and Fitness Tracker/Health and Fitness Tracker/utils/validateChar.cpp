#include "validateChar.hpp"
#include <regex>
#include <iostream>
using namespace std;

bool validateChar(string input){
    // check if input is just y/Y or n/N
    regex validChar(R"(^[yYnN]$)");
    return regex_match(input,validChar);
}
