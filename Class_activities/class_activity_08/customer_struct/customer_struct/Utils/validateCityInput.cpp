#include "validateCityInput.hpp"
#include <regex>
using namespace std;

bool validateCity(string input){
    regex reg(R"([A-Za-z\s]+)");
    return regex_match(input, reg);
}
