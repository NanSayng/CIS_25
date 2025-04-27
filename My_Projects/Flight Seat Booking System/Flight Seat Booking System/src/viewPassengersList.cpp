#include "viewPassengersList.hpp"

void viewPassengersList(){
    int num = 1;
    cout << "\nPassengers list: \n";
    if(!passengers.empty()){
        for(auto& passengerPair: passengers){
            cout << num << ". " << passengerPair.second.name << " | Age: " << passengerPair.second.age << " | Phone: " << passengerPair.second.contact << " | Passport: " << passengerPair.second.passportNumber << " | Seat: " << passengerPair.second.seatNumber ;
            if(passengerPair.second.seatClass == SeatClass::First){
                cout << " (First class)\n";
            }else if(passengerPair.second.seatClass == SeatClass::Business){
                cout << " (Business class)\n";
            }else{
                cout << " (Economy class)\n";
            }
            num++;
        }
    }else{
        cout << "There's no passengers to view.\n";
    }
}
