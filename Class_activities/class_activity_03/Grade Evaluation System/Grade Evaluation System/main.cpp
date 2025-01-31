#include <iostream>
using namespace std;

int main(){
    int score;
    cout << "Enter the score: ";
    cin >> score;
    
    if(score < 60)
        cout << "Fail!\n";
    else if(score >= 60 && score <= 69)
        cout << "Pass!\n";
    else if(score >= 70 && score <= 89)
        cout << "Good!\n";
    else if(score >= 90)
        cout << "Excellent!\n";
    
    return 0;
}
