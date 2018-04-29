#include "../include/queue.h"

Queue::Queue() : List() {}

Queue::Queue(int mCapacity) : List(mCapacity) {}

void Queue::push_back(int nel){
    insertAt(mSize, nel);
}

int Queue::pop_front(){
    int val = at(0);
    removeFrom(0);

    return val;
}