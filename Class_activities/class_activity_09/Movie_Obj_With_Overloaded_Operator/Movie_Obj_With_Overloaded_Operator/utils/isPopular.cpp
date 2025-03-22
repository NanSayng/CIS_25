#include "isPopular.hpp"

bool isPopular(){
    char ch;
    while(true){
        cout << "Is the movie popular (y/n)?: ";
        cin >> ch;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        ch = tolower(ch);
        if(ch == 'y'){
            return true;
        }
        if(ch == 'n'){
            return false;
        }
        cout << "Invalid input. Enter 'y' for yes or 'no' for no.\n";
    }
}
