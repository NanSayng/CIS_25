#include <iostream>
#include <fstream>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

enum class SeatClass {First, Business, Economy};

struct Seat{
    SeatClass seatClass;
    string seatNumber;
    bool isBooked;
};

struct Passenger{
    string name;
    string contact;
    string passportNumber;
    SeatClass seatClass;
    string seatNumber;
};

map<string, Seat> seats;
unordered_map<string, Passenger> passengers;

void displayMenu();
int getValidChoice();
void initializeSeats();
void saveToSeatFile();
void saveToPassengersFile();
void loadFromFile();
void viewFlightSeats();
void bookFlightSeat();
void cancelBooking();
void exitProgram();

void bookFlightSeat(){
    cout << "Booking a Seat...\n\n";
    string name, phoneNum, passportNum, seatNumber;
    int age, choice;
    SeatClass seatClass = SeatClass::Economy;
    cout << "Enter passenger name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter age: ";
    cin >> age;
    cout << "Enter phone number: ";
    cin >> phoneNum;
    cout << "Enter passport number: ";
    cin >> passportNum;
    cout << "\n\nSelect seat class:\n";
    cout << "1.\tFirst Class\n";
    cout << "2.\tBusiness Class\n";
    cout << "3.\tEconomy Class\n";
    cout << "Enter your choice: ";
    cin >> choice;
    if(choice == 1){
        seatClass = SeatClass::First;
        cout << "Available seats in First Class:\n";
        for(const auto& seatPair : seats){
            if(seatPair.second.seatClass == SeatClass::First && seatPair.second.isBooked == false){
                cout << "[" << seatPair.first << "] Available  ";
            }
        }
    }else if(choice == 2){
        seatClass = SeatClass::Business;
        cout << "Available seats in Business Class:\n";
        for(const auto& seatPair : seats){
            if(seatPair.second.seatClass == SeatClass::Business && seatPair.second.isBooked == false){
                cout << "[" << seatPair.first << "] Available  ";
            }
        }
    }else if(choice == 3){
        seatClass = SeatClass::Economy;
        cout << "Available seats in Economy Class:\n";
        for(const auto& seatPair : seats){
            if(seatPair.second.seatClass == SeatClass::Economy && seatPair.second.isBooked == false){
                cout << "[" << seatPair.first << "] Available  ";
            }
        }
    }
    while(true){
        cout << "\n\nEnter seat number to book: ";
        cin >> seatNumber;
        if(seats.find(seatNumber) != seats.end()){
            if(!seats[seatNumber].isBooked && seats[seatNumber].seatClass == seatClass){
                seats[seatNumber].isBooked = true;
                cout << "\nSeat " << seatNumber << " has been successfully booked for " << name << endl;
                break;
            }else{
                cout << "Seat " << seatNumber << " is already booked.\n"
            }
        }else{
            cout << "\nInvalid seat number.\n";
        }
    }
    passengers[passportNum] = Passenger(name, phoneNum, passportNum, seatClass, seatNumber);
    saveToPassengersFile();
    saveToSeatFile();
}

int main(){
    initializeSeats();
    string seatsFile = "seats.txt";
    displayMenu();
    int choice = getValidChoice();
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
            break;
    }
}


void displayMenu(){
    cout << "--- Welcome to Nan's Airline ---\n";
    cout << "1.\tView flight seats\n";
    cout << "2.\tBook a seat\n";
    cout << "3.\tCancel booking\n";
    cout << "4.\tExit\n";
}

// works fine
int getValidChoice(){
    int choice;
    while(true){
        cout << "Enter your choice(1-4): ";
        cin >> choice;
        if(cin.fail() || choice < 1 || choice > 4){
            cout << "Invalid choice. Please try again.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }else{
            break;
        }
    }
    return choice;
}

// works fine
void initializeSeats(){
    for(int i = 1; i <= 5; i++){
        seats[to_string(i) + "A"] = Seat{SeatClass::First, to_string(i) + "A", false};
        seats[to_string(i) + "B"] = Seat{SeatClass::Business, to_string(i) + "B", false};
        seats[to_string(i) + "C"] = Seat{SeatClass::Economy, to_string(i) + "C", false};
    }
}

// works fine
void viewFlightSeats(string seatsFile){
    ifstream file(seatsFile);
    if(!file){
        cout << "Error opening the file.\n";
    }
    cout << "Available Seats: \n";
    cout << "First Class: \n";
    for(const auto& seatPair : seats){
        if(seatPair.second.seatClass == SeatClass::First){
            if(seatPair.second.isBooked == false){
                cout << "[" << seatPair.first << "] Available  ";
            }else{
                cout << "[" << seatPair.first << "] Booked  ";
            }
        }
    }
    cout << endl;
    cout << "Business Class:\n";
    for(const auto& seatPair : seats){
        if(seatPair.second.seatClass == SeatClass::Business){
            if(seatPair.second.isBooked == false){
                cout << "[" << seatPair.first << "] Available  ";
            }else{
                cout << "[" << seatPair.first << "] Booked  ";
            }
        }
    }
    cout << endl;
    cout << "Economy Class:\n";
    for(const auto& seatPair : seats){
        if(seatPair.second.seatClass == SeatClass::Economy){
            if(seatPair.second.isBooked == false){
                cout << "[" << seatPair.first << "] Available  ";
            }else{
                cout << "[" << seatPair.first << "] Booked  ";
            }
        }
    }
}
