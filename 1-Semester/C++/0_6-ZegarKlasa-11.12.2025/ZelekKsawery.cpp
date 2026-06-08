// ----------------------------------------------------------------
// ---      Autor: Ksawery Zelek
// ----------------------------------------------------------------

#include <iostream>
#include <string>
#include "Clock.hpp"
using namespace std;

// ----------------------------------------------------------------

string line( '-', 32 );

// ----------------------------------------------------------------
//                      METODY
// ----------------------------------------------------------------

int Clock::tick()
{
    seconds++;

    if( seconds >= 60 )
    {
        seconds = 0;  
        minutes++;

        if( minutes >= 60 )
        {
            minutes = 0; 
            hours++;

            if( hours >= 24 )
            {
                hours = 0;
            }
        }
    }
    
    return 0; 
}

// ----------------------------------------------------------------

int Clock::changeHours( int h )
{
    hours += h;

    hours = hours % 24;

    if( hours < 0 )
    {
        hours += 24;
    }

    return hours;
}

// ----------------------------------------------------------------

int Clock::changeMinutes( int m )
{
    minutes += m;

    if( minutes >= 60 )
    {
        int leftMinutes = minutes / 60;
        minutes = minutes % 60;

        changeHours( leftMinutes );
    }
    else if( minutes < 0 )
    {
        int leftMinutes = minutes / 60;
        minutes = minutes % 60;

        if( minutes < 0 )
        {
            minutes += 60;
            leftMinutes--;
        }

        changeHours( leftMinutes );
    }

    return 0;
}

// ----------------------------------------------------------------

int Clock::changeSeconds( int s )
{
    seconds += s;

    if( seconds >= 60 )
    {
        int leftSeconds = seconds / 60;
        seconds = seconds % 60;

        changeMinutes( leftSeconds );
    }
    else if( seconds < 0 )
    {
        int leftSeconds = seconds / 60;
        seconds = seconds % 60;

        if( seconds < 0 )
        {
            seconds += 60;
            leftSeconds--;
        }

        changeMinutes( leftSeconds );
    }

    return 0;
}

// ----------------------------------------------------------------

// Porównujemy "ten" zegar (this) z zegarem "y"
void Clock::compareClocks( Clock y )
{
    if( ( hours == y.hours ) && ( minutes == y.minutes ) && ( seconds == y.seconds ) )
    {
        cout << line << "\n";
        cout << "\tZegary wskazuja ta sama godzine\n";
        cout << line << "\n";
    }
    else
    {
        cout << line << "\n";
        cout << "\tZegary NIE wskazuja tej samej godziny\n";
        cout << line << "\n";
    }
}

// ----------------------------------------------------------------

void Clock::printClock()
{
    cout << "\n" << line << "\n";
    cout << "\t\t ZEGAR\n";
    cout << "Aktualna godzina: " << hours << ":" << minutes << ":" << seconds << "\n";
    cout << line << "\n";
}

// ----------------------------------------------------------------

string Clock::toString()
{
    string output = "";

    if( hours < 10 )
    {
        output += "0";
    }
    
    output += to_string( hours );
    output += ":";

    if( minutes < 10 )
    {
        output += "0";
    }

    output += to_string( minutes );
    output += ":";

    if( seconds < 10 )
    {
        output += "0";
    }

    output += to_string( seconds );

    return output;
}

// ----------------------------------------------------------------
//                              MAIN

int main()
{
    Clock z1;                  
    Clock z2( 23, 59, 50 );     

    cout << line << "\n";
    cout << "Start Zegar 1: " << z1.toString() << "\n";
    cout << "Start Zegar 2: " << z2.toString() << "\n";
    cout << line << "\n";

    cout << "Test tick() dla Zegar 2 (15 razy):" << "\n";
    for( int i = 0; i < 15; i++ )
    {
        z2.tick();
    }
    cout << "Zegar 2 po tickach: " << z2.toString() << "\n";
    cout << line << "\n";

    cout << "Test changeSeconds( 3666 ) dla Zegar 1:" << "\n";
    z1.changeSeconds( 3666 );
    cout << "Zegar 1 wynik: " << z1.toString() << "\n";
    cout << line << "\n";

    cout << "Test changeMinutes( -125 ) dla Zegar 2:" << "\n";
    z2.changeMinutes( -125 );
    cout << "Zegar 2 wynik: " << z2.toString() << "\n";
    cout << line << "\n";

    
    cout << "Test changeHours( -25 ) dla Zegar 1:" << "\n";
    z1.changeHours( -25 );
    cout << "Zegar 1 wynik: " << z1.toString() << "\n";
    cout << line << "\n";

    return 0;
}

// ----------------------------------------------------------------