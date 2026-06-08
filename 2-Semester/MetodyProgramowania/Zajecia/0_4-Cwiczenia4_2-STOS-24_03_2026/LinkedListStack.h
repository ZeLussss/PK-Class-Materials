#ifndef LINKED_LIST_STACK_H
#define LINKED_LIST_STACK_H

struct Node
{
    int data;
    Node* next;
};

class LinkedListStack
{
private:
    Node* head;  
    int count;   

public:
    LinkedListStack();
    ~LinkedListStack();

    bool isEmpty();
    int getSize();
    int peek();
    void push( int value );
    void pop();
};

#endif