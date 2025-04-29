#include "../include/validateUserInputs.hpp"

// check if input is just y/Y or n/N
bool isValidChar(string& input){
    regex validChar(R"(^[yYnN]$)");
    return regex_match(input,validChar);
}

// allowed only 1-5 number
bool isValidChoice(string& choice){
    regex validChoice(R"(^[1-5]$)");
    return regex_match(choice, validChoice);
}

// to check if it's just number with exactly 10 digits; starts with 150
bool isValidContact(string& contact){
    regex validContact("^150\\d{7}$");
    return regex_match(contact, validContact);
}

// to check if string input contain only letters and spaces
bool isValidName(string& name){
    regex validName(R"(^[A-Za-z ]*$)");
    return regex_match(name, validName);
}

// check if input start with alphabet and followed by 6 nums
bool isValidPassNum(string& passport){
    regex validPassportNum("^[A-Za-z]\\d{6}$");
    return regex_match(passport, validPassportNum);
}

// to check if the seat number is valid in this airline
bool isValidSeatNum(string& seatNum){
    regex validSeatNum("^[1-5][A-C]$");
    return regex_match(seatNum, validSeatNum);
}
