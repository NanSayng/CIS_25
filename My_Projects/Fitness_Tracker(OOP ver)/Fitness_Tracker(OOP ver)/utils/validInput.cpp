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
    if(regex_match(name, reg))
        return true;
    return false;
}

bool validGender(const string& gender){
    regex reg(R"(^[mMfF]$)");
    if(regex_match(gender, reg)){
        return true;
    }
    return false;
}

