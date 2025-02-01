#include <iostream>
using namespace std;

int main(){
    int year;
    cout << "Enter: ";
    cin >> year;
    bool isLeapYear;
    
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        isLeapYear = true;
    else
        isLeapYear = false;
    
    if(isLeapYear)
        cout << "Year " << year << " is a leap year.\n";
    else
        cout << "Year " << year << " is not a leap year.\n";
    
    return 0;
}
