#include <cstdio>
#include "stack.h"

Stack::Stack()
{
    _first_ptr = nullptr;
}

Stack::~Stack()
{
    while(!isEmpty())
        pop();
}

bool Stack::isEmpty()
{
    return _first_ptr == nullptr;
}

void Stack::push(int value)
{
    Node *ptr = new Node(value);
    ptr->next_ptr = _first_ptr;
    _first_ptr = ptr;   
}

int Stack::pop()
{
    Node *ptr = _first_ptr;
    int value = ptr->value;
    _first_ptr = ptr->next_ptr;
    delete ptr;
    return value;
}

int Stack::top()
{
    return _first_ptr->value;
}

void Stack::print()
{
    printf("first_ptr -->[ ");
    for(Node *ptr = _first_ptr; ptr != nullptr; ptr = ptr->next_ptr)
    {
        printf("%d ", ptr->value);       
    }
    printf("]\n");
}