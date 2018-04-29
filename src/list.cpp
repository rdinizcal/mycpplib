#include "../include/list.h"

List::List() {
    mSize = 0;
    mCapacity = DEFAULT_CAP;
    mArray = new int[DEFAULT_CAP];
}

List::List(int capacity) {
    mSize = 0;
    mCapacity = capacity;
    mArray = new int[mCapacity];
}

List::~List() {
    delete[] mArray;
}

int List::size() const {
    return mSize;
}

bool List::isEmpty() const {
    return (mSize==0?true:false);
}

int List::at(int pos) {
    if(isEmpty() || pos>=mSize) return -1;

    return mArray[pos];
}

void List::insertAt(int pos, int nel) {
    if(isEmpty() || pos>=mSize ) {
        mArray[mSize] = nel;
        mSize++;
    } else {
        int j = mSize;
        while(j>=pos){
            mArray[j] = mArray[j-1];
            j--;
        }
        mArray[pos] = nel;
        mSize++;
    }
}

void List::removeFrom(int pos) {
    if(isEmpty() || pos >= mSize) return;

    int i = pos;
    while(i < mSize-1){
        mArray[i] = mArray[i+1];
        i++;
    }
    mSize--;
}



