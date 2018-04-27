#ifndef STACK_H
#define STACK_H

#include "list.h"
#include <iostream>

class Stack : public List {

    public:
        Stack();
        Stack(int /*capacity*/);

        void push_back(int /*new element*/);
        int pop_back();

    private:
        
};

#endif