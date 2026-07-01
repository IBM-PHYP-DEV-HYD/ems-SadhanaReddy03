#ifndef UTILS_H
#define UTILS_H

#include<iostream>
using namespace std;

namespace util{

      // Employee Management System Enums
    enum MainMenu {
        ADD_EMP = 1,
        REMOVE_EMP,
        EMP_DETAILS,
        OTHERS,
        EXIT_APP
    };

    enum AddMenu {
        ADD_RANDOM = 1,
        ADD_TYPE,
        ADD_BACK
    };

    enum DetailsMenu {
        ALL_EMP = 1,
        BY_TYPE,
        BY_GENDER,
        BY_STATUS,
        BY_ID,
        DETAILS_BACK
    };

    enum OthersMenu {
        ADD_LEAVES = 1,
        CONVERT_INTERN,
        SEARCH_ID,
        SEARCH_NAME,
        OTHERS_BACK
    };
  
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
    inline string genderToString(Gender gParm) {
        return (Gender::MALE == gParm) ? "Male" : "Female";
    }

    inline string statusToString(EmployeeStatus sParm) {
        if (EmployeeStatus::ACTIVE == sParm) return "Active";
        if (EmployeeStatus::INACTIVE == sParm) return "Inactive";
        return "Resigned";
    }

    inline string typeToString(EmployeeType tParm) {
        if (EmployeeType::FULL_TIME == tParm) return "Full-Time";
        if (EmployeeType::CONTRACTOR == tParm) return "Contractor";
        return "Intern";
    }

    inline string agencyToString(Agency aParm) {
        if (aParm == AVENGERS) return "Avengers";
        if (aParm == JUSTICE_LEAGUE) return "Justice League";
        return "X-Men";
    }

    inline string collegeToString(College cParm) {
        switch (cParm) {
            case IIT_DELHI: return "IIT Delhi";
            case IIT_MUMBAI: return "IIT Mumbai";
            case IIT_KANPUR: return "IIT Kanpur";
            case IIT_HYDERABAD: return "IIT Hyderabad";
            case NIT_WARANGAL: return "NIT Warangal";
            case NIT_TRICHY: return "NIT Trichy";
            case IIIT_HYDERABAD: return "IIIT Hyderabad";
        }
        return " ";
    }

    inline string branchToString(Branch bParm) {
        if (bParm == CSE) return "CSE";
        if (bParm == CSIT) return "CSIT";
        return "ECE";
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
        int mDay;
        int mMonth;
        int mYear;
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
    void readValue(T& valueParm,const string& messageParm){
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
                    cout<<"Invalid Input, "<<messageParm;
                    continue;
                }
            }
            cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"Invalid input, "<<messageParm;
        }
    }
}
#endif