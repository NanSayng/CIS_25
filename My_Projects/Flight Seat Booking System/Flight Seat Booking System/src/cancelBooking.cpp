#include "cancelBooking.hpp"

void cancelBooking(){
    string name, passportNum;
    char ch;
    cout << "Enter passenger name: ";
    cin >> name;
    cout << "Enter passport number: ";
    cin >> passportNum;
    
    auto it = passengers.find(passportNum);
    if(it != passengers.end()){
        cout << "Booking found: Seat " << (*it).second.seatNumber << endl;
        cout << "Are you sure you want to cancel this booking? (y/n): ";
        cin >> ch;
        if(ch == 'y'){
            for(auto& seatPair : seats){
                if(seatPair.second.seatNumber == (*it).second.seatNumber){
                    seatPair.second.isBooked = 0;
                    // upgrade seats file
                    saveToSeatsFile();
                    // remove passenger from unordered_map
                    passengers.erase(passportNum);
                    // upgrade passengers file
                    saveToPassengersFile(passengers);
                    break;
                }
            }
            cout << "Booking for " << name << " has been cancelled. Seat " << (*it).second.seatNumber << " is not available.\n";
        }else if(ch == 'n'){
            
        }
    }else{
        cout << "No booking found under that name and passport number.\n";
    }
};
