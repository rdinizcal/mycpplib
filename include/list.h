#ifndef LIST_H
#define LIST_H

#define DEFAULT_CAP 100

class List {

    public:
        List();
        List(int /*capacity*/);
        ~List();

        int size() const;
        bool isEmpty() const;
        int at(int /*position*/);

    protected:
        void insertAt(int /*position*/, int /*newElement*/);
        void removeFrom(int /*position*/);
        
    protected:
        int mSize;
        int mCapacity;
        int *mArray;

};

#endif