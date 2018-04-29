#ifndef LIST_H
#define LIST_H

#define DEFAULT_CAP 100

#include <iostream>

class List {

    public:
        List();
        List(int /*capacity*/);
        List(int /*size*/, int* /*array*/);
        ~List();

        int size() const;
        bool isEmpty() const;
        int at(int /*position*/);

        void insertionSort();

        void toString();

    protected:
        void insertAt(int /*position*/, int /*newElement*/);
        void removeFrom(int /*position*/);
    
    private:
        void swap(int /*pos1*/,int /*pos2*/);
        
    protected:
        int mSize;
        int mCapacity;
        int *mArray;

};

#endif