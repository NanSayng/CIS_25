#include "getValidCurrWeight.hpp"
#include "utils/validateDouble.hpp"
#include <iostream>
using namespace std;

double getValidCurrWeight(){
    string input;
    double currWeight;
    while(true){
        cout << "Enter your current weight in kg: ";
        cin >> input;
        // check if user input is valid
        if(input.empty() || !validateDouble(input)){
            cout << "Invalid weight.\n";
        }else
            break;
    }
    // converting from string to double
    currWeight = stod(input);
    return currWeight;
}
