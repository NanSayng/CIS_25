#include "isValidChar.hpp"

bool isValidChar(string& input){
    // check if input is just y/Y or n/N
    regex validChar(R"(^[yYnN]$)");
    return regex_match(input,validChar);
}

