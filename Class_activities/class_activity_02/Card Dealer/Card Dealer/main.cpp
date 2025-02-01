#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
using namespace std;

int main(){
    const int width = 40,
    numCards = 13;
    string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    int randCardNum, randSuitNum;
    string randCard;
    
    // pick random card number and suit
    srand(time(nullptr));
    randCardNum = rand() % numCards + 1;
    randSuitNum = rand() % (sizeof(suits) / sizeof(suits[0]));
    
    // final random card
    randCard = (randCardNum == 1) ? "Ace": (randCardNum == 11) ? "Jack": (randCardNum == 12) ? "Queen": (randCardNum == 13) ? "King" : to_string(randCardNum);
    randCard += " of " + suits[randSuitNum];
    
    // display the card
    cout << setfill('*') << setw(width) << '*' << endl;
    cout << endl;
    cout << left << setfill('-') << setw(width/2) << "Casino Card:" << right << setw(width/2) << randCard << endl;
    cout << endl;
    cout << setfill('*') << setw(width) << '*' << endl;
}
