#include "validateDouble.hpp"
#include <regex>
#include <iostream>
using namespace std;

bool validateDouble(string input){
    // to check if string input is just numbers and spacees with no letters, special characters or leading zero
    regex reg(R"(^([1-9][0-9]*|0)(\.[0-9]+)?$)");
    return regex_match(input,reg);
}
