#include "getValidGoalWeight.hpp"
#include "utils/validateDouble.hpp"
#include <iostream>
using namespace std;

double getValidGoalWeight(){
    string input;
    double goalWeight;
    // to check if input is only int or double without letters or special char
    while(true){
        cout << "Enter your goal weight in kg: ";
        cin >> input;
        // check if user input is valid or empty
        if(input.empty() || !validateDouble(input)){
            cout << "Invalid weight.\n";
        }else
            break;
    }
    // converting from string to double
    goalWeight = stod(input);
    return goalWeight;
}
