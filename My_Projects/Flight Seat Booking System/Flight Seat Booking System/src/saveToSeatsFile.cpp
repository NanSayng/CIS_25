#include "saveToSeatsFile.hpp"

void saveToSeatsFile(){
    fstream file("seats.txt", ios::out);
    if(!file.is_open()){
        cout << "Error opening the seats file.\n";
        return;
    }
    for(auto& seatPair : seats){
        if(seatPair.second->seatClass == SeatClass::First){
            file << seatPair.second->seatNumber << " First " << seatPair.second->isBooked << endl;
        }
    }
    for(auto& seatPair: seats){
        if(seatPair.second->seatClass == SeatClass::Business){
            file << seatPair.second->seatNumber << " Business " << seatPair.second->isBooked << endl;
        }
    }
    for(auto& seatPair: seats){
        if(seatPair.second->seatClass == SeatClass::Economy){
            file << seatPair.second->seatNumber << " Economy " << seatPair.second->isBooked << endl;
        }
    }
    file.close();
}


