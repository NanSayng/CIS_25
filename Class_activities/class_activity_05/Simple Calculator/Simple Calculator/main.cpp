#include <iostream>
using namespace std;

int main(){
    char opt;
    cout << "Choose the operation (+, -, *, /): ";
    cin >> opt;
    int num1, num2;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;
    
    switch (opt) {
        case '+':
            cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
            break;
        case '-':
            cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
            break;
        case '*':
            cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
            break;
        case '/':
            if(num2 == 0)
                cout << "Error! Cannot be divided by zero!";
            else
                cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
            break;
        default:
            cout << "Invalid operation!\n";
            break;
    }
    
    return 0;
}
