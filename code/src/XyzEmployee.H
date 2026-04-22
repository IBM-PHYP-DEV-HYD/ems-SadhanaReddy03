#ifndef XYZ_EMPLOYEE_H
#define XYZ_EMPLOYEE_H
#include<iostream>
#include "XyzEmployeeIF.H"
#include "utils.H"
using namespace util;
using namespace std;
class XyzEmployee : public XyzEmployeeIF {
    protected:
        string mName;
        string mID;
        EmployeeType mType;
        Gender mGender;
        EmployeeStatus mStatus;
        Date mDOB;
        Date mDOJ;
        Date mDOL;
    public:
        XyzEmployee(string nameParm, string idParm, EmployeeType typeParm, Gender genderParm, Date dobParm, Date dojParm) : mName(nameParm), mID(idParm), mType(typeParm), mGender(genderParm), mDOB(dobParm), mDOJ(dojParm) {
        mStatus = ACTIVE;
        // DOL = 0/0/0 (NA)
        mDOL={0,0,0};
    }
    string getName() const override {
        return mName;
    }
    string getID() const override {
        return mID;
    }
    EmployeeType getType() const override {
        return mType;
    }
    Gender getGender() const override {
        return mGender;
    }
    EmployeeStatus getStatus() const override {
        return mStatus;
    }
    Date getDOB() const override {
        return mDOB;
    }
    Date getDOJ() const override {
        return mDOJ;
    }
    Date getDOL() const override {
        return mDOL;
    }

    void setStatus(EmployeeStatus statusParm) override {
        mStatus = statusParm;
    }
    void setDOJ(const Date& dojParm) override {
        mDOJ = dojParm;
    }
    void setDOL(const Date& dolParm) override {
        mDOL = dolParm;
    }
    virtual void printEmployeeDetails() const override {
        cout << "Name: " << mName << endl;
        cout << "ID: " << mID << endl;
        cout << "Type: " << (mType == FULL_TIME ? "FullTime" : "Other") << std::endl;
        cout << "Gender: " << mGender << endl;
        cout << "Status: " << mStatus << endl;

        cout << "DOB: " << mDOB.day << "/" << mDOB.month << "/" << mDOB.year << endl;
        cout << "DOJ: " << mDOJ.day << "/" << mDOJ.month << "/" << mDOJ.year << endl;

        if (mDOL.year != 0) {
            cout << "DOL: " << mDOL.day << "/" << mDOL.month << "/" << mDOL.year << endl;
        } else {
            cout << "DOL: NA" << endl;
        }
    }
    virtual ~XyzEmployee() {}
};

#endif