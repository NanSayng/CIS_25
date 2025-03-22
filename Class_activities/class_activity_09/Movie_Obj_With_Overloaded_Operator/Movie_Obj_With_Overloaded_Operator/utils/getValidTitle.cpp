#include "getValidTitle.hpp"

void getValidTitle(string& title){
    regex reg(R"(^[A-Za-z1-9 ]+$)");
    while(true){
        cout << "Enter the movie title: ";
        getline(cin, title);
        if(title.empty() || !regex_match(title, reg)){
            cout << "Invalid title.\n";
        }else{
            break;
        }
    }
}
