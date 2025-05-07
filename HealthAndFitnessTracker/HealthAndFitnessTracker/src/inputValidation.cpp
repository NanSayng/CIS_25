#include "../include/inputValidation.h"

// check if input is just y/Y or n/N
bool validateChar(const string& input){
    regex validChar(R"(^[yYnN]$)");
    return regex_match(input,validChar);
}

// to check if string input is just numbers and spacees with no letters, special characters or leading zero
bool validateDouble(const string& input){
    regex reg(R"(^([1-9][0-9]*|0)(\.[0-9]+)?$)");
    return regex_match(input,reg);
}

// to check if string input contain only letters and spaces
bool validateInt(const string& input){
    regex reg(R"(^\s*[1-9][0-9]*\s*$)");
    return regex_match(input,reg);
}

// to check if string input contain only letters and spaces
bool validateString(const string& input){
    regex reg(R"(^[A-Za-z ]*$)");
    return regex_match(input,reg);
}


