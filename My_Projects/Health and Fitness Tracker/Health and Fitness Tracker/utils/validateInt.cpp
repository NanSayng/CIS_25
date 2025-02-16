#include "validateInt.hpp"
#include <regex>
using namespace std;

bool validateInt(string str){
    // to check if string input contain only letters and spaces
    regex reg(R"(^\s*[1-9][0-9]*\s*$)");
    return regex_match(str,reg);
}
