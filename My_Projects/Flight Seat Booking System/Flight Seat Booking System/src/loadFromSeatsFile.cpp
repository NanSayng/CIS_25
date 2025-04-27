#include "loadFromSeatsFile.hpp"

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
