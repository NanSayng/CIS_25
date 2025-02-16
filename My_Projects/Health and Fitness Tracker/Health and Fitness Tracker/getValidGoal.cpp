#include "getValidGoal.hpp"
#include <iostream>
#include <regex>
using namespace std;

int getValidGoal(){
    string input;
    int goal;
    // to make sure the string only contain 1 to 3
    regex reg(R"(^[1-3]$)");
    cout << "\nWhat is your fitness goal?\n";
    cout << "1. Lose Weight\n";
    cout << "2. Gain Muscle\n";
    cout << "3. Maintain Weight\n";
    while(true){
        cout << "Enter your choice (1-3): ";
        cin >> input;
        // check if user's goal choice is valid
        if(input.empty() || !regex_match(input,reg))
        {
            cout << "Invalid choice.\n";
        }else
            break;
    }
    // converting from string to int
    goal = stoi(input);
    return goal;
}
