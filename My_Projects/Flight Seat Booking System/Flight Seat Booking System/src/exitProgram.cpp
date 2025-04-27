#include "exitProgram.hpp"

void exitProgram(){
    string input;
    cout << "Are you sure you want to exit? (y/n): ";
    cin >> input;
    if(input == "Y" || input == "y"){
        cout << "I hope you a wonderful day. Bye!\n";
        exit(0);
    }else{
        int choice;
        do{
            string seatsFile = "seats.txt";
            displayMenu();
            choice = getValidChoice();
            switch(choice){
                case 1:
                    viewFlightSeats(seatsFile);
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
    }
};
