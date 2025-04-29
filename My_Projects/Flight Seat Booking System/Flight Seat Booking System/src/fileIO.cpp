#include "../include/fileIO.hpp"

void loadFromPassengersFile(unordered_map<string, unique_ptr<Passenger>>& passengers){
    fstream file("passengers.dat", ios::in | ios::binary);
    if(!file.is_open()){
        cout << "Error opening the passengers file.\n";
        return;
    }
    Passenger passenger;
    while(file.read(reinterpret_cast<char*>(&passenger), sizeof(Passenger))){
        passengers[passenger.passportNumber] = make_unique<Passenger>(passenger);
    }
    file.close();
}

void loadFromSeatsFile(string& seatsFile, map<string, shared_ptr<Seat>>& seats){
    fstream file(seatsFile, ios::in);
    if(!file.is_open()){
        cout << "Error opening the seats file.\n";
        return;
    }
        string seatNum;
        string seatClassStr;
        bool isBooked;
    
        while(file >> seatNum >> seatClassStr >> isBooked){
            SeatClass seatClass;
            if(seatClassStr == "First"){
                seatClass = SeatClass::First;
            }else if(seatClassStr == "Business"){
                seatClass = SeatClass::Business;
            }else{
                seatClass = SeatClass::Economy;
            }
            seats[seatNum] = make_shared<Seat>(Seat{seatClass, seatNum, isBooked});
        }
    file.close();
}

void saveToPassengersFile(unordered_map<string, unique_ptr<Passenger>>& passengers){
    fstream file("passengers.dat", ios::out | ios::binary);
    if(!file.is_open()){
        cout << "Error opening the passengers file.\n";
        return;
    }
    
    for(auto& passengerPair : passengers){
        file.write(reinterpret_cast<char*>(passengerPair.second.get()), sizeof(Passenger));
    }
    file.close();
}

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





