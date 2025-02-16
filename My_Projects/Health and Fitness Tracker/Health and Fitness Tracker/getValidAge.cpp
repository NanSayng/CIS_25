#include "getValidAge.hpp"
#include "utils/validateInt.hpp"
#include <iostream>
#include <string>
using namespace std;

int getValidAge(){
    string input;
    int age;
    while(true){
        cout << "Enter your age: ";
        getline(cin,input);
        // check if the age input is just number or invalid or zero
        if(input.empty() || !validateInt(input) || input == "0"){
            cout << "Invalid age.\n";
        }else
            break;
    }
    // converting from string to int
    age = stoi(input);
    return age;
}
