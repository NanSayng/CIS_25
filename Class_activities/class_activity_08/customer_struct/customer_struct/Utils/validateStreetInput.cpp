#include "validateStreetInput.hpp"
#include <regex>
using namespace std;

bool validateStreet(string input){
    regex reg(R"(^\s*[A-Za-z0-9\s]+\s*$)");
    return regex_match(input, reg);
}
