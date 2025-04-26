#include <iostream>
#include <filesystem>
#include "include/loadFromSeatsFile.hpp"
#include "include/displayMenu.hpp"
#include "utils/getValidChoice.hpp"
#include "include/viewFlightSeats.hpp"
#include "include/bookFlightSeat.hpp"
#include "include/cancelBooking.hpp"
#include "include/exitProgram.hpp"
using namespace std;

int main(){
    string seatsFile = "seats.txt";
    loadFromSeatsFile(seatsFile, seats);
        displayMenu();
        int choice = getValidChoice();
        switch(choice){
            case 1:
                viewFlightSeats(seatsFile);
                break;
            case 2:
                bookFlightSeat();
                break;
            case 3:
                //cancelBooking();
                break;
            case 4:
                //exitProgram();
                break;
            default:
                break;
        }
}

/*-------- To check the seats map working fine -------- */
//for(auto& seatPair : seats){
//    if(seatPair.second.seatClass == SeatClass::First){
//        cout << seatPair.second.seatNumber << " First ";
//        if(seatPair.second.isBooked){
//            cout << "1" << endl;
//        }else{
//            cout << "0" << endl;
//        }
//        
//    }
//    if(seatPair.second.seatClass == SeatClass::Business){
//        cout << seatPair.second.seatNumber << " Business ";
//        if(seatPair.second.isBooked){
//            cout << "1" << endl;
//        }else{
//            cout << "0" << endl;
//        }
//    }
//    if(seatPair.second.seatClass == SeatClass::Economy){
//        cout << seatPair.second.seatNumber << " Economy ";
//        if(seatPair.second.isBooked){
//            cout << "1" << endl;
//        }else{
//            cout << "0" << endl;
//        }
//        
//    }
//}

