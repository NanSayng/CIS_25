#include "getValidName.hpp"
#include "utils/validateString.hpp"
#include <iostream>
using namespace std;

string getValidName(){
    string name;
    while(true){
        cout << "Enter your name: ";
        getline(cin, name);
        // check if it's invalid name or empty
        if(name.empty() || !validateString(name)){
            cout << "Invalid name.\n";
        }else{
            break;
        }
    }
    return name;
}
