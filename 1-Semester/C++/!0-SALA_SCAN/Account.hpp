#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Account
{
private:
    string firstName;
    string surname;
    int age;

    // Wprowadzić enum class, który daje odpowiedz czy ktos jest adminem, czy nauczycielem czy uczniem
    bool isAdmin;                       // 1 - yes, 0 - no
    void grantUser( Account acc );


public:
    // Constructors
    Account::Account( string name = "", string surname = "", int age = 0 ) : firstName( name ), surname( surname ), age( age ) { }

    // Methods
    void editUser( Account acc );
};

// ------------------------------------------------------------------
// Constructors
// ------------------------------------------------------------------

// ------------------------------------------------------------------
// Private Methods
// ------------------------------------------------------------------

void Account::grantUser( Account acc )
{
    // Kilka opcji dodać

    // 1. Jeżeli ktoś jest adminem, może nadawać admina innym osobom oraz zabierać prawa.
    //    Admin może wszystko

    // 2. Jeżeli ktoś nie jest adminem, ale jest nauczycielem, nie może nadawać admina ani zabierać,
    //    ale może nadawać uczniom opcje szukania klasy, oraz opcje wejścia w grafik sali, kto kiedy ma zajęcia

    // 3. Uczeń może przegladac klasy, do ktorych ma dostep, oraz przegladac plan zajęć

    if( isAdmin )
    {
        // !!!!!!!!!!!!!!!!!!!!
        // DODAĆ OPCJE, ŻEBY SPRAWDZIC CZY USER JUZ NIE JEST ADMINEM
        // Jeżeli jest pominąć opcje wyboru i wyjsc z funkcji

        cout << "Are u sure, that u want to grant " << acc.firstName << " " << acc.surname << " to admin?\n";
        cout << "[ 1 - yes, 0 - no ]: ";
        
        short choose;
        cin >> choose;

        if( choose )
        {
            acc.isAdmin = true;
        }
        else if( choose == 0 )
        {
            acc.isAdmin = false;
        }
    }
}

// ------------------------------------------------------------------

// ------------------------------------------------------------------
// Public Methods
// ------------------------------------------------------------------

void Account::editUser( Account acc )
{
    // To samo co w funkcji grantUser(), zwrocic uwage na to, kto kim jest i uważać z nadawaniem dostępu
    if( isAdmin )
    { 
        // Wszystkie funkcje wraz z opcją nadania admina
    }
    else
    {
        // Brak funkcji nadania admina
    }
}

// ------------------------------------------------------------------

// ------------------------------------------------------------------