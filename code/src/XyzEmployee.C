#include "XyzEmployee.H"
#include <iostream>
using namespace std;
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
    cout << "Name: " << mName << endl;
    cout << "ID: " << mID << endl;
    cout << "Type: " << typeToString(mType) << endl;
    cout << "Gender: " << genderToString(mGender) << endl;
    cout << "Status: " << statusToString(mStatus) << endl;

    cout << "DOB: " << mDOB.mDay << "/" << mDOB.mMonth << "/" << mDOB.mYear << endl;
    cout << "DOJ: " << mDOJ.mDay << "/" << mDOJ.mMonth << "/" << mDOJ.mYear << endl;

    if (mDOL.mYear != 0)
        cout << "DOL: " << mDOL.mDay << "/" << mDOL.mMonth << "/" << mDOL.mYear << endl;
    else
        cout << "DOL: NA" << endl;
}

XyzEmployee::~XyzEmployee() {}