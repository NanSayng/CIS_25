#include <iostream>
#include "include/fileIO.hpp"
#include "include/booking.hpp"
#include "include/display.hpp"
#include "include/validateUserInputs.hpp"
using namespace std;

int main(){
    string seatsFile = "seats.txt";
    loadFromSeatsFile(seatsFile, seats);
    string passengersFile = "passengers.dat";
    loadFromPassengersFile(passengersFile, passengers);
    int choice;
    do{
        displayMenu();
        // get valid choice
        while(true){
            cout << "Enter your choice (1-5): ";
            cin >> choice;
            string choiceStr = to_string(choice);
            // check if it's empty or invalid
            if(choiceStr.empty() || !isValidChoice(choiceStr)){
                cout << "Invalid choice.\n";
            }else{
                break;
            }
        }
        switch(choice){
            case 1:
                viewFlightSeats();
                break;
            case 2:
                bookFlightSeat();
                break;
            case 3:
                cancelBooking();
                break;
            case 4:
                viewPassengersList();
                break;
            case 5:
                exitProgram();
                break;
            default:
                break;
        }
    }while(choice != 5);
    
    return 0;
}

