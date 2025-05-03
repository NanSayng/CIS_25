#include "../include/fileIO.hpp"

void loadFromPassengersFile(const string& passengersFile, unordered_map<string, unique_ptr<Passenger>>& passengers){
    fstream file(passengersFile, ios::in | ios::binary);
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

void loadFromSeatsFile(const string& seatsFile, map<string, shared_ptr<Seat>>& seats){
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

// update to passengersFile
void saveToPassengersFile(const string& passengersFile, unordered_map<string, unique_ptr<Passenger>>& passengers){
    fstream file(passengersFile, ios::out | ios::binary);
    if(!file.is_open()){
        cout << "Error opening the passengers file.\n";
        return;
    }
    
    for(const auto& passengerPair : passengers){
        const Passenger& p = *(passengerPair.second);
            file.write(reinterpret_cast<const char*>(&p), sizeof(Passenger));
        }
    file.close();
}

// update to seats file
void saveToSeatsFile(const string& seatsFile, map<string, shared_ptr<Seat>>& seats){
    fstream file(seatsFile, ios::out);
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





