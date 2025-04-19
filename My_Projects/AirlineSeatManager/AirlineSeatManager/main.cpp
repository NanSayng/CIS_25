#include <iostream>
#include <fstream>
#include <iomanip>
#include <map>
#include <unordered_map>
using namespace std;

// enum class
enum class SeatClass {First, Business, Economy};
enum class SeatStatus {Booked, Unbooked};

// structs
struct FlightSeat{
    SeatClass seatClass;
    string seatNumber;
    SeatStatus availability;
};

struct PassengerSeat{
    SeatClass seatClass;
    string seatNumber;
};

struct Passenger{
    string name;
    int age;
    string phoneNumber;
    string passportNumber;
    PassengerSeat seatInfo;
};

// object declaration
Passenger passenger;

void viewAvailSeats(){
    cout << "\nAvailable Seats:\n\n";
    // display available seats
    // First
    // Business
    // Economy
};

string getSeatNumber(){
    viewAvailSeats();
    string seatNumber;
    cout << "Enter seat number to book: ";
    cin >> seatNumber;
    return seatNumber;
}

SeatClass getSeatclass(){
    int choice;
    cout << "\nSelect seat class:\n";
    cout << "1.\tFirst Class\n";
    cout << "2.\tBusiness Class\n";
    cout << "3.\tEconomy Class\n";
    while(true){
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
            case 1: return SeatClass::First;
                break;
            case 2: return SeatClass::Business;
                break;
            case 3: return SeatClass::Economy;
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}

void getPassengerInfo(){
    string name = passenger.name;
    int age = passenger.age;
    string phoneNumber = passenger.phoneNumber;
    string passportNumber = passenger.passportNumber;
    cout << "Enter passenger name: ";
    getline(cin, name);
    cout << "Enter Age: ";
    cin >> age;
    cout << "Enter phone number: ";
    cin >> phoneNumber;
    cout << "Enter passport number: ";
    cin >> passportNumber;
}

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

int getMenuChoice(){
    int choice;
    cout << "\nPlease enter your choice: ";
    cin >> choice;
    return choice;
}


void bookSeats(){
    cout << "\n--- Booking FLight Seat ---" << endl;
    getPassengerInfo();
    passenger.seatInfo.seatClass = getSeatclass();
    viewAvailSeats();
    passenger.seatInfo.seatNumber = getSeatNumber();
    cout << "\nSeat " << passenger.seatInfo.seatNumber << " successfully booked for " << passenger.name << ".\n";
}
void cancelBooking(){
    cout << "Enter passenger name: ";
    // check if name exists
    // display seat if found
    // ask if they want to cancel again
}

void viewPassengerList(){
    // display the passenger lists (passenger.txt)
}

void exitMenu(){
    // exit the program
};

int main(){
    displayMainMenu();
    bookSeats();
    int menuChoice = getMenuChoice();
    switch(menuChoice){
        case'1':
            viewAvailSeats();
            break;
        case'2':
            bookSeats();
            break;
        case'3':
            cancelBooking();
            break;
        case'4':
            viewPassengerList();
            break;
        case '5':
            exitMenu();
        default:
            break;
    }
}
