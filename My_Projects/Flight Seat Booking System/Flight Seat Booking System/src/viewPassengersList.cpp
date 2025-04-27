#include "viewPassengersList.hpp"

void viewPassengersList(){
    int num = 1;
    cout << "\nPassenger List: \n";
    if(!passengers.empty()){
        for(auto& passengerPair: passengers){
            cout << num << ". " << passengerPair.second.name << " | Age: " << passengerPair.second.age << " | Phone: " << passengerPair.second.contact << " | Passport: " << passengerPair.second.passportNumber << " Seat: " << passengerPair.second.seatNumber << endl;
            num++;
        }
    }else{
        cout << "There's no passengers to view.\n";
    }
}
