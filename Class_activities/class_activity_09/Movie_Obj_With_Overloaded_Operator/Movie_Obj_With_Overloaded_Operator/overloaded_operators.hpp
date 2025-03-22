#ifndef overloaded_operators_hpp
#define overloaded_operators_hpp
#include <iostream>
#include "Movie.hpp"
using namespace std;

ostream& operator << (ostream& stream, const Time& durationTime);
ostream& operator << (ostream& stream, const Date& releaseDate);
ostream& operator << (ostream& stream, const Movie& movie);

#endif /* overloaded_operators_hpp */
