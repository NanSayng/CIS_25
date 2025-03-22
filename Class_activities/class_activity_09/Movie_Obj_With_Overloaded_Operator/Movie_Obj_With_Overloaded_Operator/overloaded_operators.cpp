#include "overloaded_operators.hpp"

ostream& operator << (ostream& stream, const Time& durationTime){
    stream << durationTime.hour << " hr: " << durationTime.min << " min: " << durationTime.sec << " sec"<< endl;
    return stream;
}

ostream& operator << (ostream& stream, const Date& releaseDate){
    stream << releaseDate.releaseMonth << '/' << releaseDate.releaseDay << '/' << releaseDate.releaseYear << endl;
    return stream;
}

ostream& operator << (ostream& stream, const Movie& movie){
    stream <<"Title: " << movie.title << '\n';
    stream << "Release date: " << movie.releaseDate;
    stream << "Duration: " << movie.duration;
    stream << "Director: " << movie.director << '\n';
    if(movie.isPopular){
        stream << "This movie is popular.\n";
    }else{
        stream << "This movie is not popular.\n";
    }
    return stream;
}
