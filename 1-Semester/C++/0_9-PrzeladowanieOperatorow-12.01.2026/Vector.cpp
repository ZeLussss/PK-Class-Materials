#include "Vector.h"
#include <iostream>
#include <stdexcept>
#include <algorithm> // Required for std::min

using namespace std;

Vector::Vector( int dimension )
    : dim( dimension )
{
    if( dim < 1 )
    {
        dim = 1;
    }
    x = new double[ dim ];
    // Initialize with 0 to prevent garbage values
    for( int i = 0; i < dim; i++ )
    {
        x[ i ] = 0;
    }
}

Vector::Vector( const Vector & v )
{
    dim = v.dim;
    x = new double[ dim ];
    for( int i = 0; i < dim; i++ )
    {
        x[ i ] = v.x[ i ];
    }
}

Vector::~Vector()
{
    // std::cout << "removing vector : " << *this << std::endl;
    delete[] x;
}

Vector & Vector::operator=( const Vector & v )
{
    // Check for self-assignment
    if( this == &v )
    {
        return *this;
    }

    if( dim != v.dim )
    {
        delete[] x;
        dim = v.dim;
        x = new double[ dim ];
    }
    for( int i = 0; i < dim; i++ )
    {
        x[ i ] = v.x[ i ];
    }
    
    return *this; // FIXED: This was missing!
}

// Operator []
double & Vector::operator[]( int index )
{
    if( index < 1 || index > dim )
    {
        throw out_of_range( "Wykroczono poza wykres" );
    }
    return x[ index - 1 ];
}

// Operator [] const
const double & Vector::operator[]( int index ) const
{
    if( index < 1 || index > dim )
    {
        throw out_of_range( "Wykroczono poza wykres" );
    }
    return x[ index - 1 ];
}

// Operator +=
Vector & Vector::operator+=( const Vector & other )
{
    if( dim != other.dim )
    {
        throw invalid_argument( "Niezgodne wymiary wektorow" );
    }
    for( int i = 0; i < dim; i++ )
    {
        x[ i ] += other.x[ i ];
    }
    return *this;
}

// Operator -=
Vector & Vector::operator-=( const Vector & other )
{
    if( dim != other.dim )
    {
        throw invalid_argument( "Niezgodne wymiary wektorow" );
    }
    for( int i = 0; i < dim; i++ )
    {
        x[ i ] -= other.x[ i ];
    }
    return *this;
}

// Operator *=
Vector & Vector::operator*=( double scalar )
{
    for( int i = 0; i < dim; i++ )
    {
        x[ i ] *= scalar;
    }
    return *this;
}

// Operator +
Vector operator+( Vector left, const Vector & right )
{
    left += right;
    return left;
}

// Operator -
Vector operator-( Vector left, const Vector & right )
{
    left -= right;
    return left;
}

// Iloczyn Skalarny
double operator*( const Vector & left, const Vector & right )
{
    if( left.dim != right.dim )
    {
        throw invalid_argument( "Niezgodne wymiary wektorow" );
    }
    double sum = 0.0;
    for( int i = 0; i < left.dim; i++ )
    {
        sum += left.x[ i ] * right.x[ i ];
    }
    return sum;
}

// Operator ==
bool operator==( const Vector & left, const Vector & right )
{
    if( left.dim != right.dim )
    {
        return false;
    }
    for( int i = 0; i < left.dim; i++ )
    {
        if( left.x[ i ] != right.x[ i ] )
        {
            return false;
        }
    }
    return true;
}

// Operator !=
bool operator!=( const Vector & left, const Vector & right )
{
    return !( left == right );
}

// Operator <
bool operator<( const Vector & left, const Vector & right )
{
    int n = min( left.dim, right.dim );
    for( int i = 0; i < n; i++ )
    {
        if( left.x[ i ] < right.x[ i ] )
        {
            return true;
        }
        if( left.x[ i ] > right.x[ i ] )
        {
            return false;
        }
    }
    return left.dim < right.dim;
}

// Operator >
bool operator>( const Vector & left, const Vector & right )
{
    return right < left;
}

// Operator <=
bool operator<=( const Vector & left, const Vector & right )
{
    return !( right < left );
}

// Operator >=
bool operator>=( const Vector & left, const Vector & right )
{
    return !( left < right );
}

// <<
std::ostream & operator<<( std::ostream & out, const Vector & v )
{
    out << "(";
    for( int i = 0; i < v.dim - 1; ++i )
    {
        out << v.x[ i ] << ", ";
    }
    if( v.dim > 0 )
    {
        out << v.x[ v.dim - 1 ];
    }
    out << ")";
    return out;
}