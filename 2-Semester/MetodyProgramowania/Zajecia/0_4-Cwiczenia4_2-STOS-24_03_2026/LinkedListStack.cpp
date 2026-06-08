#include <iostream>
#include "LinkedListStack.h"

using namespace std;

// Konstruktor domyslny
LinkedListStack::LinkedListStack()
{
    head = nullptr;
    count = 0;
}

LinkedListStack::~LinkedListStack()
{
    while( !isEmpty() )
    {
        pop();
    }
}

bool LinkedListStack::isEmpty()
{
    return head == nullptr;
}

int LinkedListStack::getSize()
{
    return count;
}

int LinkedListStack::peek()
{
    if( isEmpty() )
    {
        cout << "Blad: Stos (lista) jest pusty!\n";
        return -1;
    }
    return head->data;
}

void LinkedListStack::push( int value )
{
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    count++;
}

void LinkedListStack::pop()
{
    if( isEmpty() )
    {
        cout << "Blad: Nie mozna usunac z pustego stosu!\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    count--;
}