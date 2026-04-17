#ifndef DEQUE_H
#define DEQUE_H
#include"utils.H"
using namespace util;

template <class T>
class Deque{
    protected:
        Node<T>* mFront;
        Node<T>* mBack;
        int mSize;

    public:
        Deque();
        ~Deque();
        Deque(int nParm, T xParm);
        void pushBack(T valueParm);
        void pushFront(T valueParm);
        void popBack();
        void popFront();
        T front();
        T back();
        bool empty();
        int size();
        void resize(int newSizeParm,T defaultParm,int directionParm);
        void clear();
        void display();
        T operator[](int indexParm);
};

template <class T>
Deque<T>::Deque()
//Default constructor, initialises empty deque
: mFront(nullptr), mBack(nullptr), mSize(0) {}

template <class T>
Deque<T>::Deque(int nParm, T xParm)
: mFront(nullptr), mBack(nullptr), mSize(0){
    /*Parameterized constructor
    creates a deque with nParm elements with value xParm
    */
    for(int sCount=0;sCount<nParm;sCount++){
        pushBack(xParm);
    }
}

template <class T>
Deque<T>::~Deque(){
    // Destructor
    clear();
}

template <class T>
bool Deque<T> :: empty(){
    /*
    checks whether the deque is empty
    */
    return mSize==0;
}

template<class T>
void Deque<T> :: pushBack(T valueParm){
    /*
    Inserts a new element at back of deque
    */
    Node<T>* sTemp=new Node<T>(valueParm);
    if(empty()){
        mFront=sTemp;
        mBack=sTemp;
    }
    else{
        mBack->mNext=sTemp;
        sTemp->mPrev=mBack;
        mBack=sTemp;
    }
    mSize++;
}

template <class T>
void Deque<T> :: pushFront(T valueParm){
    /*
    inserts a new element at front of deque
    */
    Node<T>* sTemp=new Node<T>(valueParm);
    if(empty()){
        mFront=sTemp;
        mBack=sTemp;
    }
    else{
        sTemp->mNext=mFront;
        mFront->mPrev=sTemp;
        mFront=sTemp;
    }
    mSize++;
}

template<class T>
void Deque<T> :: popBack(){
    /*
    removes last element from deque
    */
    if(empty()){
        cout<<"Deque is empty";
        return;
    }
    Node<T>* sTemp;
    sTemp=mBack;
    mBack=mBack->mPrev;
    if(mBack){
        mBack->mNext=nullptr;
    }
    else{    
        mFront=nullptr;
    }
    delete sTemp;
    mSize--;
}

template<class T>
void Deque<T>:: popFront(){
    /*
    removes first element from deque
    */
    if(empty()){
        cout<<"Deque is Empty";
        return;
    }
    Node<T>* sTemp;
    sTemp=mFront;
    mFront=mFront->mNext;
    if(mFront){
        mFront->mPrev=nullptr;
    }
    else{    
        mBack=nullptr;
    }
    delete sTemp;
    mSize--;
}

template<class T>
T Deque<T> :: front(){
    /*
    returns first element of deque
    */
    if(empty()) {
        throw runtime_error("Deque is empty");
    }
    cout<<"First element : ";
    return mFront->mData;
}

template<class T>
T Deque<T> :: back(){
    /*
    returns last element of deque
    */
    if(empty()) {
        throw runtime_error("Deque is empty");
    }
    cout<<"Last Element: ";
    return mBack->mData;
}

template<class T>
int Deque<T> :: size(){
    /*
    returns current number of elements in deque
    */
    cout<<"Size of Deque: ";
    return mSize;
}

template<class T>
void Deque<T> :: clear(){
    /*
    removes all the elements from the deque
    */
    if(empty()){
        cout<<"Deque is Empty";
        return;
    }
    while(!empty()){
        popFront();
    }
}

template <class T>
void Deque<T>:: resize(int newSizeParm,T defaultParm,int directionParm){
    /*
    resizes deque to newSizeParm according to the direction
    */
    if(newSizeParm>mSize){
        while(mSize<newSizeParm){
            if(directionParm==1){
                pushBack(defaultParm);
            }
            else{
                pushFront(defaultParm);
            }
        }   
    }
    else{
        while(mSize>newSizeParm){
            if(directionParm==1){
                popBack();
            }
            else{
                popFront();
            }
        }
    }
    return;
}

template<class T>
void Deque<T>:: display(){
    /*
    prints all elements of deque
    */
    if(empty()){
        cout<<"deque is empty"<<endl;
        return;
    }
    cout<<"Deque:  ";
    Node<T>* sTemp;
    sTemp=mFront;
    while(sTemp!=nullptr){
        cout<<sTemp->mData<<"  ";
        sTemp=sTemp->mNext;
    }
}

template<class T>
T Deque<T>:: operator[](int indexParm){
    /*
    returns element at given index
    */
    Node<T>* sTemp;
    sTemp=mFront;
    int sIndex=0;
    while(sTemp!=nullptr && sIndex<indexParm){
        sTemp=sTemp->mNext;
        sIndex++;
    }
    if(sTemp!=nullptr){
        return sTemp->mData;
    }
    cout<<"index out of deque size"<<endl;
    return T();
}
#endif