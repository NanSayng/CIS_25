#include <iostream>
#include <iomanip>
using namespace std;

enum class SeatClass {First, Business, Economy};

struct FlightSeat{
    SeatClass seatClass;
    string seatNumber;
    bool availability;
};

struct Passenger{
    string name;
    int age;
    string phoneNumber;
    string passportNumber;
};

void displayMainMenu(){
    cout << setfill('-') << setw(22) << '-' << endl;
    cout << "Welcome to Nan's Airline\n";
    cout << setfill('-') << setw(22) << '-' << endl;
    cout << "1.\tView Available Seats\n";
    cout << "2.\tBook flight seats\n";
    cout << "3.\tCancel booking\n";
    cout << "4.\tView passengers lists\n";
    cout << "5.\tExit menu\n";
}

void viewAvailSeats();
void bookSeats();
void cancelBooking();
void viewPassengerList();

int main(){
    displayMainMenu();
}
