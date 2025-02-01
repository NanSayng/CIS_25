#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    char op;
    cout << "Choose the operation (+, -, *, /): ";
    cin >> op;
    double num1, num2;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;
    
    switch (op) {
        case '+':
            cout << num1 << " " << op << " " << num2 << " = " << num1 + num2 << endl;
            break;
        case '-':
            cout << num1 << " " << op << " " << num2 << " = " << num1 - num2 << endl;
            break;
        case '*':
            cout << num1 << " " << op << " " << num2 << " = " << num1 * num2 << endl;
            break;
        case '/':
            if(num2 == 0)
                cout << "Error! Cannot be divided by zero!\n";
            else
                cout << num1 << " " << op << " " << num2 << " = " << num1 / num2 << endl;
            break;
        default:
            cout << "Invalid operation!" << endl;
            break;
    }
    return 0;
}
