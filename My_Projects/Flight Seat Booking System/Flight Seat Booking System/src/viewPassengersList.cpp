#include "viewPassengersList.hpp"

void viewPassengersList(){
    int num = 1;
    cout << "\nPassengers list: \n";
    if(!passengers.empty()){
        for(auto& passengerPair: passengers){
            // dereference unique_ptr to access each Passenger object
            auto& passenger = *passengerPair.second;
            // display passenger information
            cout << num << ". " << passenger.name << " | Age: " << passenger.age << " | Phone: " << passenger.contact << " | Passport: " << passenger.passportNumber << " | Seat: " << passenger.seatNumber ;
            if(passenger.seatClass == SeatClass::First){
                cout << " (First class)\n";
            }else if(passenger.seatClass == SeatClass::Business){
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
