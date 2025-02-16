#include "getValidGender.hpp"
#include <iostream>
#include <regex>
using namespace std;

bool getValidGender(){
    bool isMale = false;
    string input;
    regex validGender(R"(^[mMfF]$)");
    while(true){
        cout << "Enter your gender 'm/M' for Male, 'f/F' for Female: ";
        cin >> input;
        // check if the input is empty or invalid
        if(input.empty() || !regex_match(input,validGender)){
            cout << "Invalid gender.\n";
        } else
            break;
    }
    if(input == "M" || input == "m"){ // if male, assigned isMale = true or else assigned false for female
        isMale = true;
    }
    return isMale;
}
