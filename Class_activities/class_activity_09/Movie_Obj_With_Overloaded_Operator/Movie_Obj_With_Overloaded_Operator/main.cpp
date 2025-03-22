#include <iostream>
#include <iomanip>
#include "Movie.hpp"
#include "getValidTitle.hpp"
#include "getValidReleaseDate.hpp"
#include "getValidTimeDuration.hpp"
#include "getValidDirector.hpp"
#include "isPopular.hpp"
#include "overloaded_operators.hpp"
using namespace std;


int main(){
    Movie movie;
    getValidTitle(movie.title);
    getValidReleaseDate(movie.releaseDate.releaseMonth,
                        movie.releaseDate.releaseDay,
                        movie.releaseDate.releaseYear);
    getValidTimeDuration(movie.duration.hour,
                         movie.duration.min,
                         movie.duration.sec);
    getValidDirector(movie.director);
    movie.isPopular = isPopular();
    // display
    cout << "\n";
    cout << setfill(' ') << setw(23) << "Movie Information" << endl;
    cout << setfill('-') << setw(30) << '-' << endl;
    cout << movie << endl;
}
