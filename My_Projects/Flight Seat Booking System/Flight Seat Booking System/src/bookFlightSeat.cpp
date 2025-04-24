#include "bookFlightSeat.hpp"

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
                cout << "Seat " << seatNumber << " is already booked.\n";
            }
        }else{
            cout << "\nInvalid seat number.\n";
        }
    }
    passengers[passportNum] = Passenger(name, phoneNum, passportNum, seatClass, seatNumber);
    //saveToPassengersFile();
    //saveToSeatFile();
}
