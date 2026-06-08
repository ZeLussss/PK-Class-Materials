#include <iostream>
#include <string>
using namespace std;

// 

class Clock
{
public:
    Clock() : hours( 0 ), minutes( 0 ), seconds( 0 ) { };

    Clock( int h, int m = 0, int s = 0 )
    {
        hours = h;
        minutes = m;
        seconds = s;
    };

    int tick();

    int changeHours( int h );
    int changeMinutes( int m );
    int changeSeconds( int s );

    void compareClocks( Clock y );

    void printClock();

    string toString();

private:
    int hours;
    int minutes;
    int seconds;
};
