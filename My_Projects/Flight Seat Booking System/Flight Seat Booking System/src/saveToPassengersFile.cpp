#include "saveToPassengersFile.hpp"

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
