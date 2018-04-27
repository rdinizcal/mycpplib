#ifndef QUEUE_H
#define QUEUE_H

#include "list.h"

class Queue : public List {

    public:
        Queue();
        Queue(int /*capacity*/);

        void push_back(int /*new element*/);
        int pop_front();

    private:
};

#endif