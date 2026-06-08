#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

class ArrayStack
{
private:
    int* array;      
    int capacity;    
    int topIndex;    

public:
    ArrayStack( int cap = 100 );
    ~ArrayStack();

    bool isEmpty();
    int getSize();
    int peek();
    void push( int value );
    void pop();
};

#endif