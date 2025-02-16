#include <iostream>
#include <iomanip>
#include <string>
#include "getUserInfo.hpp"
#include "displayMainMenu.hpp"
using namespace std;

User user;

int main(){
    // title
    cout << setfill(' ') << setw(50) << "Welcome to Nan's Health and Fitness Tracker\n";
    cout << setfill('-') << setw(57) << '-' << endl;
    // get user's information
    getUserInfo(user);
    // display main menu and perform the program
    displayMainMenu(user);
    return 0;
}
