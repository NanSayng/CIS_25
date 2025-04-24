#include "getValidChoice.hpp"

int getValidChoice(){
    int choice;
    while(true){
        cout << "Enter your choice(1-4): ";
        cin >> choice;
        if(cin.fail() || choice < 1 || choice > 4){
            cout << "Invalid choice. Please try again.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }else{
            break;
        }
    }
    return choice;
}
