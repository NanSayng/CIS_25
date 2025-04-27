#include "validateNameInput.hpp"

bool validateNameInput(string& name){
    // to check if string input contain only letters and spaces
    regex reg(R"(^[A-Za-z ]*$)");
    return regex_match(name, reg);
}
