#include "getValidReleaseDate.hpp"

void getValidReleaseDate(short& mm, short& dd, short& yy){
    while(true){
        cout << "Enter the movie release date (mm dd yy): ";
        cin >> mm >> dd >> yy;
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid date.\n";
            continue;
        }
        
        if(mm < 1 || mm > 12){
            cout << "Invalid date.\n";
            continue;
        }
        
        if(yy < 1888 || yy > 2025){
            cout << "Invalid year.\n";
            continue;
        }
        
        int maxDay;
        switch(mm){
            case 4: case 6: case 9: case 11:
                maxDay = 30;
                break;
            case 2:
                if(yy % 4 == 0 && yy % 100 != 0 || yy % 400 == 0){
                    maxDay = 29;
                }else{
                    maxDay = 28;
                }
                break;
            default:
                maxDay = 31;
        }
        if(dd < 1 || dd > maxDay){
            cout << "Invalid date.\n";
            continue;
        }
        break;
    }
}
