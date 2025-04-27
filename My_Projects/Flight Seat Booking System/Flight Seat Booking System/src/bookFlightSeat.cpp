#include "bookFlightSeat.hpp"

void bookFlightSeat(){
    Passenger newPassenger;
    cout << "Booking a Seat...\n\n";
    int choice;
    while(true){
        cout << "Enter passenger name: ";
        cin.ignore();
        cin.getline(newPassenger.name, sizeof(newPassenger.name));
        // convert from char to string to check validation
        string nameStr(newPassenger.name);
        if(nameStr.empty() || !isValidName(nameStr)){
            cout << "Invalid name.\n";
        }else{
            break;
        }
    }
    while(true){
        cout << "Enter age: ";
        cin >> newPassenger.age;
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter valid age.\n";
        }else if(newPassenger.age < 12){
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Under the age of 12 years old cannot book a flight.\n";
        }else{
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }
    
    cout << "Enter phone number: ";
    cin.ignore();
    cin.getline(newPassenger.contact, sizeof(newPassenger.contact));
    
    cout << "Enter passport number: ";
    cin.getline(newPassenger.passportNumber, sizeof(newPassenger.passportNumber));
    
    cout << "\n\nSelect seat class:\n";
    cout << "1.\tFirst Class\n";
    cout << "2.\tBusiness Class\n";
    cout << "3.\tEconomy Class\n";
    cout << "Enter your choice: ";
    cin >> choice;
    
    if(choice == 1){
        newPassenger.seatClass = SeatClass::First;
        cout << "Available seats in First Class:\n";
        for(const auto& seatPair : seats){
            if(seatPair.second->seatClass == SeatClass::First && !seatPair.second->isBooked){
                cout << "[" << seatPair.first << "] Available  ";
            }
        }
    }else if(choice == 2){
        newPassenger.seatClass = SeatClass::Business;
        cout << "Available seats in Business Class:\n";
        for(const auto& seatPair : seats){
            if(seatPair.second->seatClass == SeatClass::Business && !seatPair.second->isBooked){
                cout << "[" << seatPair.first << "] Available  ";
            }
        }
    }else if(choice == 3){
        newPassenger.seatClass = SeatClass::Economy;
        cout << "Available seats in Economy Class:\n";
        for(const auto& seatPair : seats){
            if(seatPair.second->seatClass == SeatClass::Economy && !seatPair.second->isBooked){
                cout << "[" << seatPair.first << "] Available  ";
            }
        }
    }
    
    while(true){
        cout << "\n\nEnter seat number to book: ";
        cin.ignore();
        cin.getline(newPassenger.seatNumber, sizeof(newPassenger.seatNumber));
        if(seats.find(newPassenger.seatNumber) != seats.end()){
            if(!seats[newPassenger.seatNumber]->isBooked && seats[newPassenger.seatNumber]->seatClass == newPassenger.seatClass){
                seats[newPassenger.seatNumber]->isBooked = 1;
                cout << "\nSeat " << newPassenger.seatNumber << " has been successfully booked for " << newPassenger.name << endl;
                break;
            }else{
                cout << "Seat " << newPassenger.seatNumber << " is already booked.\n";
            }
        }else{
            cout << "\nInvalid seat number.\n";
        }
    }
    // save info to passengers map
    passengers[newPassenger.passportNumber] = make_unique<Passenger>(newPassenger);
    
    // update seats.txt file
    saveToSeatsFile();
    // update passengers.dat file
    saveToPassengersFile(passengers);
}
