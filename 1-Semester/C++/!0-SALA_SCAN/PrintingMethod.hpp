#include <iostream>
#include <string>
#include <vector>
using namespace std;

class PrintingMethod
{
private:
    vector< string > screen;
    int width = 0;
    int height = 0;
    
    static const int MIN_WIDTH  = 50;
    static const int MIN_HEIGHT = 30;

    // Methods
    void createEmptyScreen();
    
public:
    // Constructors
    PrintingMethod();                                           // Constructor without arg
    PrintingMethod( int x, int y );                             // Constructor with 2 arg
    PrintingMethod( PrintingMethod & other );                   // Copy constructor
    
    // Public methods
    void drawFrame();
    void printScreen();

    void createWindow( int x_SIZE, int y_SIZE );

};

// --------------------------------------------------------------
//          Constructors
// --------------------------------------------------------------

PrintingMethod::PrintingMethod()
{
    width = MIN_WIDTH;
    height = MIN_HEIGHT;
    createEmptyScreen();
}

PrintingMethod::PrintingMethod( int x, int y )
{
    // AD. Minimum x-size is 100, and y is 50, for posibility of filling the screen with data
    if( x < MIN_WIDTH )
    {
        cerr << "X too small. Setting to MIN_WIDTH." << endl;
        width = MIN_WIDTH;
    }
    else
    {
        width = x;
    }

    if( y < MIN_HEIGHT )
    {
        cerr << "Y too small. Setting to MIN_HEIGHT." << endl;
        height = MIN_HEIGHT;
    }
    else
    {
        height = y;
    }

    createEmptyScreen();
}

// --------------------------------------------------------------
//          Methods
// --------------------------------------------------------------

// --------------------------------------------------------------   Private

void PrintingMethod::createEmptyScreen()
{
    screen.clear();

    for( int i = 0; i < height; i++ )
    {
        screen.push_back( string( width, ' ' ) );
    }
}

// --------------------------------------------------------------   Public

void PrintingMethod::drawFrame()
{
    string TL = "\u256D", TR = "\u256E";
    string BL = "\u2570", BR = "\u256F";
    string H  = "\u2500", V  = "\u2502";

    string topRow = TL;
    string botRow = BL;
    string midRow = "";

    for( int i = 0; i < width - 2; i++ )
    {
        topRow += H;
        botRow += H;
        midRow += " ";
    }
    topRow += TR;
    botRow += BR;

    screen[ 0 ] = topRow;
    screen[ height - 1 ] = botRow;

    // 2. Boki
    for( int y = 1; y < height - 1; y++ )
    {
        screen[ y ] = V + midRow + V;
    }
}

void PrintingMethod::printScreen()
{
    for( const string & row : screen )
    {
        cout << row << endl;
    }
}