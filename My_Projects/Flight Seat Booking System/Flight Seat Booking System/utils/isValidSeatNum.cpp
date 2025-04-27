#include "isValidSeatNum.hpp"

bool isValidSeatNum(string& seatNum){
    // to check if the seat number is valid in this airline
    regex reg("^[1-5][A-C]$");
    return regex_match(seatNum, reg);
}
