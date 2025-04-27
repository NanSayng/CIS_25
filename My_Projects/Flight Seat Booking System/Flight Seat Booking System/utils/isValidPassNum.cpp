#include "isValidPassNum.hpp"

bool isValidPassNum(string& passport){
    // check if input start with alphabet and followed by only nums
    regex reg("^[A-Za-z0-9]{6,9}$");
    return regex_match(passport, reg);
}
