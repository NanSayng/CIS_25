#include "exitProgram.hpp"
#include "getUserInfo.hpp"
#include "displayMainMenu.hpp"
#include "getMenuOption.hpp"
#include "utils/validateChar.hpp"
#include <iostream>
using namespace std;

void exitProgram(User& user){
    string input;
    while(true){
        cout << "Are you sure you want to exit? (y/n): ";
        cin >> input;
        // check if input is valid
        if(input.empty() || !validateChar(input)){
            cout << "Invalid input.\n";
        }else
            break;
    }
    if(input == "Y" || input == "y"){
        cout << "I hope you a wonderful day. Bye!\n";
        exit(0);
    }else{
        displayMainMenu(user);
    }
}
