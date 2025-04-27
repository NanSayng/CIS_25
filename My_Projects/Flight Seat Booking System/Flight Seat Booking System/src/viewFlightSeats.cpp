#include "viewFlightSeats.hpp"

void viewFlightSeats(string seatsFile){
    ifstream file(seatsFile);
    if(!file){
        cout << "Error opening the file.\n";
    }
    cout << "\nAvailable Seats: \n";
    cout << "\nFirst Class: \n";
    for(const auto& seatPair : seats){
        if(seatPair.second->seatClass == SeatClass::First){
            if(!seatPair.second->isBooked){
                cout << "[" << seatPair.first << "] Available  ";
            }else{
                cout << "[" << seatPair.first << "] Booked  ";
            }
        }
    }
    cout << endl;
    cout << "\nBusiness Class:\n";
    for(const auto& seatPair : seats){
        if(seatPair.second->seatClass == SeatClass::Business){
            if(!seatPair.second->isBooked){
                cout << "[" << seatPair.first << "] Available  ";
            }else{
                cout << "[" << seatPair.first << "] Booked  ";
            }
        }
    }
    cout << endl;
    cout << "\nEconomy Class:\n";
    for(const auto& seatPair : seats){
        if(seatPair.second->seatClass == SeatClass::Economy){
            if(!seatPair.second->isBooked){
                cout << "[" << seatPair.first << "] Available  ";
            }else{
                cout << "[" << seatPair.first << "] Booked  ";
            }
        }
    }
    cout << endl;
}
