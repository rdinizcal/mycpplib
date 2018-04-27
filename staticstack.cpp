#include "staticstack.h"

StaticStack::StaticStack() {
    mSize = 0;
    mCapacity = DEFAULT_CAPACITY;
    mArray = new int [DEFAULT_CAPACITY];
}

StaticStack::StaticStack(int capacity) {
    if(capacity <= 0){
        std::cout << "\nError! Could not create static stack with capacity equal or smaller than 0." << std::endl;
        mCapacity = DEFAULT_CAPACITY;
    } else {
        mCapacity = capacity;
    }
    mSize = 0;
    mArray = new int [mCapacity];
};

StaticStack::~StaticStack() { 
    delete[] mArray;
}

bool StaticStack::isEmpty() const  {
    return (mSize==0)?true:false; 
};

int StaticStack::size() const {
    return mSize;
}

int StaticStack::getCapacity() const {
    return mCapacity;
}

int StaticStack::at(int position) const {
    if (position >= 0 && position <= mSize){
        return mArray[position];
    } else {
        return 0;
    }
}

void StaticStack::push(int element) {
    if(mSize>=mCapacity) {
        std::cout << "\nCould not push element into the stack." << std::endl;
    } else {
        mArray[mSize] = element;
        mSize++;
    }
}

int StaticStack::pull() {

    if(mSize > 0) {
        mSize--;
        return mArray[mSize];
    } else {
        std::cout << "\nCould not pull element from the stack." << std::endl;
        return 0;
    }
}