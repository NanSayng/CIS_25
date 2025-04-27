#include "loadFromPassengersFile.hpp"

void loadFromPassengersFile(unordered_map<string, Passenger>& passengers){
    fstream file("passengers.dat", ios::in | ios::binary);
    if(!file.is_open()){
        cout << "Error opening the passengers file.\n";
        return;
    }
    Passenger passenger;
    while(file.read(reinterpret_cast<char*>(&passenger), sizeof(passenger))){
        passengers[passenger.passportNumber] = passenger;
    }
    file.close();
}
