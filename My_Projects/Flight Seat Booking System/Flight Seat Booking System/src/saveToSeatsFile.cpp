#include "saveToSeatsFile.hpp"

void saveToSeatsFile(){
    fstream file("seats.txt", ios::out);
    if(!file.is_open()){
        cout << "Error opening the seats file.\n";
        return;
    }
    for(auto& seatPair : seats){
        file << seatPair.second.seatNumber << " ";
        if(seatPair.second.seatClass == SeatClass::First){
            file << "First " << seatPair.second.isBooked << "\n";
        }else if(seatPair.second.seatClass == SeatClass::Business){
            file << "Business " << seatPair.second.isBooked << "\n";
        }else{
            file << "Economy " << seatPair.second.isBooked << "\n";
        }
    }
    file.close();
}


