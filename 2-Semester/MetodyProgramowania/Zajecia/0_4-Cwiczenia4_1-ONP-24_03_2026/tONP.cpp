#include "tONP.h"
#include <stack>

using namespace std;

// =====================================================================
// FUNKCJE POMOCNICZE 
// =====================================================================

bool isOperand( char c )
{
    return c >= 'a' && c <= 'z';
}

int priority( char c )
{
    if( c == '~' ) return 5;
    if( c == '^' ) return 4;
    if( c == '*' || c == '/' || c == '%' ) return 3;
    if( c == '+' || c == '-' ) return 2;
    if( c == '<' || c == '>' ) return 1;
    if( c == '=' ) return 0;
    
    return -1;
}

bool isRightAssociative( char c )
{
    return c == '~' || c == '^' || c == '=';
}

bool isOperator( char c )
{
    return priority( c ) != -1;
}

// =====================================================================
// CZYSZCZENIE I WALIDACJA WEJŚCIA
// =====================================================================

string cleanExpression( const string& s, bool isINF )
{
    string res = "";
    for( char c : s )
    {
        if( isOperand( c ) ) 
        {
            res += c;
        }
        else if( isOperator( c ) ) 
        {
            res += c;
        }
        else if( isINF && ( c == '(' || c == ')' ) ) 
        {
            res += c;
        }
    }
    return res;
}

bool isValidINF( const string& s )
{
    if( s.empty() ) return false;
    
    int state = 0; 
    int parens = 0;
    
    for( char c : s )
    {
        if( c == '(' )
        {
            if( state == 1 ) return false;
            parens++;
        }
        else if( c == ')' )
        {
            if( state == 0 ) return false;
            parens--;
            
            if( parens < 0 ) return false;
        }
        else if( c == '~' )
        {
            if( state == 1 ) return false; 
        }
        else if( isOperand( c ) )
        {
            if( state == 1 ) return false; 
            state = 1;
        }
        else if( isOperator( c ) )
        {
            if( state == 0 ) return false; 
            state = 0;
        }
    }
    
    return state == 1 && parens == 0;
}

bool isValidONP( const string& s )
{
    if( s.empty() ) return false;
    
    int count = 0;
    
    for( char c : s )
    {
        if( isOperand( c ) )
        {
            count++;
        }
        else if( c == '~' )
        {
            if( count < 1 ) return false;
        }
        else if( isOperator( c ) )
        {
            if( count < 2 ) return false;
            count--;
        }
    }
    
    return count == 1; 
}

// =====================================================================
// KONWERSJE
// =====================================================================

string infToOnp( const string& inf )
{
    string onp = "";
    stack<char> st;
    
    for( char c : inf )
    {
        if( isOperand( c ) )
        {
            onp += c;
        }
        else if( c == '(' )
        {
            st.push( c );
        }
        else if( c == ')' )
        {
            while( !st.empty() && st.top() != '(' )
            {
                onp += st.top();
                st.pop();
            }
            
            if( !st.empty() ) st.pop();
        }
        else if( isOperator( c ) )
        {
            while( !st.empty() && isOperator( st.top() ) )
            {
                char top = st.top();
                
                if( ( !isRightAssociative( c ) && priority( top ) >= priority( c ) ) ||
                    ( isRightAssociative( c ) && priority( top ) > priority( c ) ) )
                {
                    onp += top;
                    st.pop();
                }
                else
                {
                    break;
                }
            }
            st.push( c );
        }
    }
    
    while( !st.empty() )
    {
        onp += st.top();
        st.pop();
    }
    
    return onp;
}

// Struktura Expr
struct Expr 
{
    string s;
    char mainOp; 
};

string onpToInf( const string& onp )
{
    stack<Expr> st;
    
    for( char c : onp )
    {
        if( isOperand( c ) )
        {
            st.push( { string( 1, c ), 0 } );
        }
        else if( c == '~' )
        {
            Expr A = st.top(); 
            st.pop();
            
            bool parens = false;
            
            if( A.mainOp != 0 && priority( A.mainOp ) < priority( c ) )
            {
                parens = true;
            }
            
            string newS = parens ? "~(" + A.s + ")" : "~" + A.s;
            st.push( { newS, c } );
        }
        else if( isOperator( c ) )
        {
            Expr R = st.top(); 
            st.pop(); 
            
            Expr L = st.top(); 
            st.pop(); 

            bool leftParens = false;
            if( L.mainOp != 0 )
            {
                if( priority( L.mainOp ) < priority( c ) ) 
                {
                    leftParens = true;
                }
                else if( priority( L.mainOp ) == priority( c ) && isRightAssociative( c ) ) 
                {
                    leftParens = true;
                }
            }

            bool rightParens = false;
            if( R.mainOp != 0 )
            {
                if( priority( R.mainOp ) < priority( c ) ) 
                {
                    rightParens = true;
                }
                else if( priority( R.mainOp ) == priority( c ) && c != '~' ) 
                {
                    rightParens = true;
                }
            }

            string newS = "";
            newS += leftParens ? "(" + L.s + ")" : L.s;
            newS += c;
            newS += rightParens ? "(" + R.s + ")" : R.s;

            st.push( { newS, c } );
        }
    }
    
    return st.top().s;
}