#include "getValidActiveLevel.hpp"
#include <iostream>
#include <regex>
using namespace std;

int getValidActiveLevel(){
    string input;
    int level;
    // allowed only 1 to 4 numbers
    regex reg(R"(^[1-4]$)");
    cout << "\nHow active are you?\n";
    cout << "1.\tSedentary (little to no exercise)\n";
    cout << "2.\tLightly Active (1-3 days exercise per week)\n";
    cout << "3.\tModerately Active (3-5 days exercise per week)\n";
    cout << "4.\tVery Active (6-7 days exercise per week\n";
    while(true){
        cout << "Enter your active level [1-4]: ";
        cin >> input;
        // check if user choice is valid
        if(input.empty() || !regex_match(input,reg)){
            cout << "Invalid choice.\n";
        }else
            break;
    }
    // converting from string to int
    level = stoi(input);
    return level;
}
