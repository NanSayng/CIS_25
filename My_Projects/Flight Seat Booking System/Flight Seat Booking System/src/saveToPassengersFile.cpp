#include "saveToPassengersFile.hpp"

void saveToPassengersFile(string& filename, unordered_map<string, Passenger>& passengers){
    fstream file(filename, ios::out | ios::binary);
    if(!file.is_open()){
        cout << "Error opening the passengers file.\n";
        return;
    }
    string name, contact, passportNum, seatClassStr, seatNum;
    for(auto& passengerPair : passengers){
        name = passengerPair.second.name;
        contact = passengerPair.second.contact;
        passportNum = passengerPair.second.passportNumber;
        if(passengerPair.second.seatClass == SeatClass::First){
            seatClassStr = "First";
        }else if(passengerPair.second.seatClass == SeatClass::Business){
            seatClassStr = "Business";
        }else{
            seatClassStr = "Economy";
        }
        string line = name + contact + passportNum + seatClassStr + seatNum;
        file.write(line.c_str(), line.size());
    }
    file.close();
}
