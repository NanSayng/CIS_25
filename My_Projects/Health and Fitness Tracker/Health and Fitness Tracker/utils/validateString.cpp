#include "validateString.hpp"
#include <regex>
using namespace std;

bool validateString(string str){
    // to check if string input contain only letters and spaces
    regex reg(R"(^[A-Za-z ]*$)");
    return regex_match(str,reg);
}
