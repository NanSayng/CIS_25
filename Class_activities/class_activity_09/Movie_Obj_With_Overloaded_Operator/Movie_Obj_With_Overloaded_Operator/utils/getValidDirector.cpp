#include "getValidDirector.hpp"

void getValidDirector(string& name){
    regex reg{R"(^[A-Za-z ]*$)"};
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while(true){
        cout << "Enter the director name: ";
        getline(cin, name);
        if(cin.fail() || name.empty() || !regex_match(name, reg)){
            cin.clear();
            cout << "Invalid name.\n";
        }else{
            break;
        }
    }
}
