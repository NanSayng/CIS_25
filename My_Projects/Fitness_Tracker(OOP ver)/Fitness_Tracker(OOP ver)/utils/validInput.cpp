//
//  isInvalidName.cpp
//  Health and Fitness Tracker (OOP version)
//
//  Created by Nan Sayng on 5/12/25.
//

#include "validInput.hpp"
#include <stdexcept>

bool validName(const string& name){
    regex reg(R"(^[A-Za-z ]*$)");
    return (regex_match(name, reg)) ? true : false;
}

bool validGender(const string& gender){
    regex reg(R"(^[mMfF]$)");
    return (regex_match(gender, reg)) ? true : false;
}

bool validCalories(const string& calories){
    regex reg(R"(^([1-9][0-9]*|0)(\.[0-9]+)?$)");
    return (regex_match(calories, reg)) ? true : false;
}

bool validHeight(const string& height){
    regex reg(R"(^([1-9][0-9]*|0)(\.[0-9]+)?$)");
    return (regex_match(height, reg)) ? true : false;
}

bool validWeight(const string& weight){
    regex reg (R"(^([1-9][0-9]*|0)(\.[0-9]+)?$)");
    return (regex_match(weight, reg)) ? true : false;
}

bool validMenuOption(const string& option){
    regex reg(R"(^[1-8]$)");
    return (regex_match(option, reg)) ? true : false;
}

bool validYesOrNo(const string& input){
    regex reg(R"(^[yYnN]$)");
    return (regex_match(input, reg)) ? true : false;
}


