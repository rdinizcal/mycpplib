#include "stack.h"

Stack::Stack() {
    mSize = 0;
    mCapacity = DEFAULT_CAPACITY;
    mArray = new int [DEFAULT_CAPACITY];
}

Stack::Stack(int capacity) {
    if(capacity <= 0){
        std::cout << "\nError! Could not create static stack with capacity equal or smaller than 0." << std::endl;
        mCapacity = DEFAULT_CAPACITY;
    } else {
        mCapacity = capacity;
    }
    mSize = 0;
    mArray = new int [mCapacity];
};

Stack::~Stack() { 
    delete[] mArray;
}

bool Stack::isEmpty() const  {
    return (mSize==0)?true:false; 
};

int Stack::size() const {
    return mSize;
}

int Stack::getCapacity() const {
    return mCapacity;
}

int Stack::at(int position) const {
    if (position >= 0 && position <= mSize){
        return mArray[position];
    } else {
        return 0;
    }
}

void Stack::push(int element) {
    if(mSize>=mCapacity) {
        std::cout << "\nCould not push element into the stack." << std::endl;
    } else {
        mArray[mSize] = element;
        mSize++;
    }
}

int Stack::pull() {

    if(mSize > 0) {
        mSize--;
        return mArray[mSize];
    } else {
        std::cout << "\nCould not pull element from the stack." << std::endl;
        return 0;
    }
}