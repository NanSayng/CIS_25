#include "getValidChoice.hpp"

int getValidChoice(){
    string input;
    int choice;
    // allowed only 1-8 number
    regex reg(R"(^[1-5]$)");
    while(true){
        cout << "\nEnter your choice (1-5): ";
        cin >> input;
        // check if choice is invalid or empty
        if(input.empty() || !regex_match(input,reg)){
            cout << "Invalid choice.\n";
        }else{
            break;
        }
    }
    choice = stoi(input);
    return choice;
}
