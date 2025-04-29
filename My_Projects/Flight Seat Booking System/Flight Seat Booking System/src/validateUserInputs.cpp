#include "../include/validateUserInputs.hpp"

bool isValidChar(string& input){
    // check if input is just y/Y or n/N
    regex validChar(R"(^[yYnN]$)");
    return regex_match(input,validChar);
}

bool isValidChoice(string& choice){
    // allowed only 1-5 number
    regex validChoice(R"(^[1-5]$)");
    return regex_match(choice, validChoice);
}

bool isValidContact(string& contact){
    // to check if it's just number with exactly 10 digits; no leading zero
    regex validContact("^[1-9]\\d{9}$");
    return regex_match(contact, validContact);
}

bool isValidName(string& name){
    // to check if string input contain only letters and spaces
    regex validName(R"(^[A-Za-z ]*$)");
    return regex_match(name, validName);
}

bool isValidPassNum(string& passport){
    // check if input start with alphabet and followed by only nums
    regex validPassportNum("^[A-Za-z0-9]{6,9}$");
    return regex_match(passport, validPassportNum);
}

bool isValidSeatNum(string& seatNum){
    // to check if the seat number is valid in this airline
    regex validSeatNum("^[1-5][A-C]$");
    return regex_match(seatNum, validSeatNum);
}
