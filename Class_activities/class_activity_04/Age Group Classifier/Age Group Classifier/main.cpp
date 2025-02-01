#include <iostream>
using namespace std;

int main(){
    int age;
    cout << "Enter your age: ";
    cin >> age;
    
    if(age <= 0)
        cout << "Invalid age!\n";
    else {
        if(age < 12)
            cout << "Child\n";
        else if(age >= 12 && age <= 19)
            cout << "Teen\n";
        else if(age >= 20 && age <= 64)
            cout << "Adult\n";
        else if(age >= 65)
            cout << "Senior\n";
    }
    
    return 0;
}
