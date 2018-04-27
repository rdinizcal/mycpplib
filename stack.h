#ifndef SSTACK_H
#define SSTACK_H

#include <iostream>

const int DEFAULT_CAPACITY = 100;

class Stack {

    public:
        Stack();
        Stack(int /*size*/);
        ~Stack();

        bool isEmpty() const;
        int size() const;
        int getCapacity() const;
        int at(int /*position*/) const;
        void push(int /*element*/);
        int pull();

        
    private:
        int mSize;
        int mCapacity;
        int *mArray; 

};

#endif