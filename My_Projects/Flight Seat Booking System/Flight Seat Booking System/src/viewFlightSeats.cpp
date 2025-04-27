#include "viewFlightSeats.hpp"

void viewFlightSeats(string seatsFile){
    ifstream file(seatsFile);
    if(!file){
        cout << "Error opening the file.\n";
    }
    cout << "Available Seats: \n";
    cout << "First Class: \n";
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
    cout << "Business Class:\n";
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
    cout << "Economy Class:\n";
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
