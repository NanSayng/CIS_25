//
//  Movie.hpp
//  Movie_Obj_With_Overloaded_Operator
//
//  Created by Nan Sayng on 3/21/25.
//

#ifndef Movie_h
#define Movie_h
#include <iostream>
#include <string>
using namespace std;

struct Time{
    short hour;
    short min;
    short sec;
};

struct Date{
    short releaseMonth;
    short releaseDay;
    short releaseYear;
};

struct Movie{
    string title;
    Date releaseDate;
    Time duration;
    string director;
    bool isPopular;
};

#endif /* Movie_h */
