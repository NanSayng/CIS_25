//
//  validInput.hpp
//  Health and Fitness Tracker (OOP version)
//
//  Created by Nan Sayng on 5/12/25.
//

#ifndef validInput_hpp
#define validInput_hpp
#include <string>
#include <regex>
using namespace std;

// to check if string input contain only letters and spaces, and not empty string
bool validName(const string& name);
bool validHeight(const string& height);
bool validGender(const string& gender);
bool validWeight(const string& weight);
bool validCalories(const string& calories);
bool validMenuOption(const string& option);
bool validYesOrNo(const string& input);

#endif /* isInvalidName_hpp */
