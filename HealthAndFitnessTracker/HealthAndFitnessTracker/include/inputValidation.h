#pragma once
#include <string>
#include <regex>
using namespace std;

// to check if string input is just y/n for yes or no
bool validateChar(const string& input);
// to check if string input is just numbers and spacees with no letters, special characters or leading zero
bool validateDouble(const string& input);
// to check if string input contain only letters and spaces
bool validateInt(const string& input);
// to check if string input contain only letters and spaces
bool validateString(const string& input);
