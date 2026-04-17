#ifndef EXTENDED_DEQUE_H
#define EXTENDED_DEQUE_H

#include "Deque.H"
// #include <stdexcept>

template <class T>
class ExtendedDeque : public Deque<T> {
public:
    ExtendedDeque();
    ExtendedDeque(int nParm, T xParm);
    ~ExtendedDeque();
    void insertAt(int indexParm, T valueParm);
    void removeAt(int indexParm);
};

template <class T>
ExtendedDeque<T>::ExtendedDeque() 
: Deque<T>() {}

template <class T>
ExtendedDeque<T>::ExtendedDeque(int nParm, T xParm) 
: Deque<T>(nParm, xParm) {}

template <class T>
ExtendedDeque<T>::~ExtendedDeque() {
}

template <class T>
void ExtendedDeque<T>::insertAt(int indexParm, T valueParm) {
    if (indexParm <= 0) {
        this->pushFront(valueParm);
        return;
    }
    if (indexParm >= this->mSize) {
        this->pushBack(valueParm);
        return;
    }
    Node<T>* sNewNode = new Node<T>(valueParm);
    Node<T>* sCurrent = this->mFront;
    for (int sCount = 0; sCount < indexParm; sCount++) {
        sCurrent = sCurrent->mNext;
    }
    sNewNode->mNext = sCurrent;
    sNewNode->mPrev = sCurrent->mPrev;
    if (sCurrent->mPrev) {
        sCurrent->mPrev->mNext = sNewNode;
    }
    sCurrent->mPrev = sNewNode;
    this->mSize++;
}

template <class T>
void ExtendedDeque<T>::removeAt(int indexParm) {
    if (this->empty()) {
        throw runtime_error("Cannot remove from empty deque");
    }
    if (indexParm < 0 || indexParm >= this->mSize) {
        throw out_of_range("Index out of bounds");
    }
    if (indexParm == 0) {
        this->popFront();
        return;
    }
    if (indexParm == this->mSize - 1) {
        this->popBack();
        return;
    }
    Node<T>* sCurrent = this->mFront;
    for (int sCount = 0; sCount < indexParm; sCount++) {
        sCurrent = sCurrent->mNext;
    }
    if (sCurrent->mPrev) {
        sCurrent->mPrev->mNext = sCurrent->mNext;
    }
    if (sCurrent->mNext) {
        sCurrent->mNext->mPrev = sCurrent->mPrev;
    }
    delete sCurrent;
    this->mSize--;
}

#endif