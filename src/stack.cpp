#include "../include/stack.h"

Stack::Stack() : List() {}

Stack::Stack(int mCapacity) : List(mCapacity) {}

void Stack::push_back(int nel){
    insertAt(mSize, nel);
}

int Stack::pop_back() {
    int val = at(mSize-1);
    removeFrom(mSize-1);

    return val;
}