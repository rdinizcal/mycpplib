#include "../include/stack.h"

Stack::Stack() : List() {}

Stack::Stack(int mCapacity) : List(mCapacity) {}

void Stack::push_back(int nel){
    insertAt(mSize, nel);
}

int Stack::pull_back() {
    int val = at(mSize-1);
    deleteAt(mSize-1);

    return val;
}