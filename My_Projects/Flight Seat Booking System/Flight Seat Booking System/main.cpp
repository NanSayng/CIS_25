#include <iostream>
using namespace std;

enum class SeatClass {First, Business, Economy};

struct Seat{
    SeatClass seatClass;
    string seatNumber;
    bool isBooked;
};

struct passenger{
    string name;
    string contact;
    string passportNumber;
};

void viewFlightSeats();
void bookFlightSeat();
void cancelBooking();
void exitProgram();

void getMenuOption(){
    int choice;
    cout << "\nEnter your choice (1-4): ";
    cin >> choice;
    while(true){
        switch(choice){
            case 1:
                viewFlightSeats();
                break;
            case 2:
                bookFlightSeat();
                break;
            case 3:
                cancelBooking();
                break;
            case 4:
                exitProgram();
                break;
            default:
                cout << "Invalid choice.\n";
        }
    }
}

void displayMenu(){
    cout << "--- Welcome to Nan's Airline ---\n";
    cout << "1.\tView flight seats\n";
    cout << "2.\tBook a seat\n";
    cout << "3.\tCancel booking\n";
    cout << "4.\tExit\n";
    getMenuOption();
}

int main(){
    displayMenu();
}
