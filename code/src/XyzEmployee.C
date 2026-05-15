#include "XyzEmployee.H"
#include <iostream>
using namespace util;

XyzEmployee::XyzEmployee(string nameParm, string idParm, EmployeeType typeParm,
                         Gender genderParm, Date dobParm, Date dojParm)
    : mName(nameParm), mID(idParm), mType(typeParm),
      mGender(genderParm), mDOB(dobParm), mDOJ(dojParm) {
    mStatus = ACTIVE;
    mDOL = {0,0,0};
}

string XyzEmployee::getName() const {
     return mName; 
}
string XyzEmployee::getID() const {
     return mID; 
}
EmployeeType XyzEmployee::getType() const {
     return mType; 
}
Gender XyzEmployee::getGender() const {
     return mGender; 
}
EmployeeStatus XyzEmployee::getStatus() const {
     return mStatus; 
}
Date XyzEmployee::getDOB() const { 
    return mDOB;
}
Date XyzEmployee::getDOJ() const { 
    return mDOJ; 
}
Date XyzEmployee::getDOL() const { 
    return mDOL; 
}

void XyzEmployee::setStatus(EmployeeStatus statusParm) {
    mStatus = statusParm;
}

void XyzEmployee::setDOJ(const Date& dojParm) {
    mDOJ = dojParm;
}

void XyzEmployee::setDOL(const Date& dolParm) {
    mDOL = dolParm;
}

void XyzEmployee::printEmployeeDetails() const {
    
    cout << "Employee Name   : " << mName << endl;
    cout << "Employee ID     : " << mID << endl;
    cout << "Employee Type   : " << typeToString(mType) << endl;
    cout << "Employee Status : " << statusToString(mStatus) << endl;
    cout << "Gender          : " << genderToString(mGender) << endl;

    cout << "Date of Birth   : "
        << mDOB.mDay << "/"
        << mDOB.mMonth << "/"
        << mDOB.mYear << endl;

    cout << "Date of Joining : "
        << mDOJ.mDay << "/"
        << mDOJ.mMonth << "/"
        << mDOJ.mYear << endl;

    if (0 != mDOL.mYear) {
        cout << "Date of Leaving : "
            << mDOL.mDay << "/"
            << mDOL.mMonth << "/"
            << mDOL.mYear << endl;
    }
    else
        cout << "DOL: NA" << endl;
}

void XyzEmployee::printEmployeeSummary() const {
    cout << "| "
         << mName << " | "
         << mID << " | "
         << typeToString(mType) << " | "
         << statusToString(mStatus) << " | "
         << genderToString(mGender) << " | "
         << mDOB.mDay << "/" << mDOB.mMonth << "/" << mDOB.mYear << " | "
         << mDOJ.mDay << "/" << mDOJ.mMonth << "/" << mDOJ.mYear << " |"
         << endl;
}
XyzEmployee::~XyzEmployee() {}