#include "getValidHeight.hpp"
#include "utils/validateDouble.hpp"
#include <iostream>
#include <string>
using namespace std;

double getValidHeight(){
    string input;
    double height;
    while(true){
        cout << "Enter your height in cm: ";
        cin >> input;
        // check if input is invalid or empty
        if(input.empty() || !validateDouble(input)){
            cout << "Invalid height.\n";
        }else{
            break;
        }
    }
    // convert from string to int
    height = stod(input);
    return height;
}
