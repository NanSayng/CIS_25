#include <iostream>
using namespace std;

struct Time{
    int hour;
    int min;
    int sec;
};

struct Date{
    short releaseDay;
    short releaseMonth;
    short releaseYear;
};

struct Movie{
    string title;
    Date releaseDate;
    Time duration;
    string director;
    char isPopular;
};

ostream& operator << (ostream& stream, const Time& durationTime){
    stream << durationTime.hour << ':' << durationTime.min << ':' << durationTime.sec << endl;
    return stream;
}

ostream& operator << (ostream& stream, const Date& releaseDate){
    stream << releaseDate.releaseMonth << '/' << releaseDate.releaseDay << '/' << releaseDate.releaseYear << endl;
    return stream;
}

ostream& operator << (ostream& stream, const Movie& movie){
    stream <<"Title: " << movie.title << '\n';
    stream << "Release date: " << movie.releaseDate << '\n';
    stream << "Duration: " << movie.duration << '\n';
    stream << "Director: " << movie.director << '\n';
    if(movie.isPopular == 'y' || movie.isPopular == 'Y'){
        stream << "This movie is popular.\n";
    }else{
        stream << "This movie is not popular.\n";
    }
    return stream;
}

int main(){
    Movie movie;
    cout << "Enter the movie name: ";
    getline(cin, movie.title);
    cout << "Enter the release date (mm/dd/yy): ";
    
    cout << "Enter the movie duration (00:00:00): ";

    cout << "Enter the movie's director: ";

    cout << "Is the movie popular? (y/n): ";

    
}
