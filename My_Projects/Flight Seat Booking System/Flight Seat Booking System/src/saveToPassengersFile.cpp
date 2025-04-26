#include "saveToPassengersFile.hpp"

void saveToPassengersFile(string& filename, unordered_map<string, Passenger>& passengers){
    fstream file(filename, ios::out | ios::binary);
    if(!file.is_open()){
        cout << "Error opening the passengers file.\n";
        return;
    }
    
    for(auto& passengerPair : passengers){
        file.write(reinterpret_cast<char*>(&passengerPair.second), sizeof(passengerPair.second));
    }
    file.close();
}
