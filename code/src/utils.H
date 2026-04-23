#ifndef UTILS_H
#define UTILS_H

#include<iostream>
using namespace std;

namespace util{
    // Employee Management System Enums
    enum Gender {
        MALE = 1,
        FEMALE
    };

    enum EmployeeType {
        FULL_TIME = 1,
        CONTRACTOR,
        INTERN
    };

    enum EmployeeStatus {
        ACTIVE = 1,
        INACTIVE,
        RESIGNED
    };

    enum Agency {
        AVENGERS = 1,
        JUSTICE_LEAGUE,
        X_MEN
    };

    enum College {
        IIT_DELHI = 1,
        IIT_MUMBAI,
        IIT_KANPUR,
        IIT_HYDERABAD,
        NIT_WARANGAL,
        NIT_TRICHY,
        IIIT_HYDERABAD
    };

    enum Branch {
        CSE = 1,
        CSIT,
        ECE
    };

    // Original Deque enums
    enum DequeType {
        INT=1,
        STRING,
        STUDENT
    };

    enum DequeKind {
        EmptyDeque=1,
        NSizeXDeque
    };

    enum DequeOperations {
        PushBack=1,
        PushFront,
        PopBack,
        PopFront,
        Front,
        Back,
        Size,
        Resize,
        Clear,
        Print
    };
    
    enum Section {
        A=1,
        B,
        C,
        D
    };

    template<typename T>
    void readValue(T& valueParm,const string& MessageParm){
        /*
        reads value of type T safely from input
        re-prompts until valid input is entered
        */
        while(true){
            if(cin>>valueParm){ 
                string sExtra;
                getline(cin,sExtra);
                if(sExtra.empty()){
                    return;
                }
                else{
                    cout<<"Invalid Input, "<<MessageParm;
                    continue;
                }
            }
            cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"Invalid input, "<<MessageParm;
        }
    }

    template <class T>
    class Node{
        public:
            T mData;
            Node<T>* mNext;
            Node<T>* mPrev;
            Node(T valueParm)
            : mData(valueParm), mNext(nullptr),mPrev(nullptr) {}
    };

    struct Date {
        int day;
        int month;
        int year;
    };
}
#endif