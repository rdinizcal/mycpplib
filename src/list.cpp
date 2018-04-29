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

List::List(int size, int *array) {
    mSize = size;
    mCapacity = DEFAULT_CAP;
    mArray = new int[DEFAULT_CAP];

    int i = 0;
    while(i<size) {
        mArray[i] = array[i];
        i++;
    }
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

void List::insertionSort() {
    
    int j = 1;

    while(j<mSize) {

        for(int i=0; i<j; i++) {
            if(mArray[i]>mArray[j]) swap(i,j);
        }
        j++;
    }
}

void List::toString() {

    std::cout << "[";
    for (int i = 0; i<mSize; i++) {
        std::cout << mArray[i];
        if(i+1<mSize) std::cout << ","; 
    }
    std::cout << "]" << std::endl;
}

void List::swap(int i, int j) {
    int temp = mArray[i];
    mArray[i] = mArray[j];
    mArray[j] = temp;
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


