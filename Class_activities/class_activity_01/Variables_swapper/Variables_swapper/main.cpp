#include <iostream>
using namespace std;

int main(){
    int x, y;
    // get the values from user
    cout << "Enter the value of x: ";
    cin >> x;
    cout << "Enter the value of y: ";
    cin >> y;
    // print the original values
    cout << "Before swapping: x = " << x << ", y = " << y << endl;
    // swapping the values
    int temp = x;
    x = y;
    y = temp;
    // print the swapped values
    cout << "After swapping: x = " << x << ", y = " << y << endl;
    return 0;
}
