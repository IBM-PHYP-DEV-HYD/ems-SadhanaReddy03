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

    string sDob = to_string(mDOB.mDay) + "/" +
                  to_string(mDOB.mMonth) + "/" +
                  to_string(mDOB.mYear);

    string sDoj = to_string(mDOJ.mDay) + "/" +
                  to_string(mDOJ.mMonth) + "/" +
                  to_string(mDOJ.mYear);

    string sDol = "NA";

    if (mDOL.mYear != 0) {
        sDol = to_string(mDOL.mDay) + "/" +
               to_string(mDOL.mMonth) + "/" +
               to_string(mDOL.mYear);
    }

    cout << left
         << "|" << setw(12) << mName
         << "|" << setw(12) << mID
         << "|" << setw(12) << typeToString(mType)
         << "|" << setw(12) << statusToString(mStatus)
         << "|" << setw(10) << genderToString(mGender)
         << "|" << setw(12) << sDob
         << "|" << setw(12) << sDoj
         << "|" << setw(15) << "NA"
         << "|" << setw(12) << "NA"
         << "|" << setw(18) << "NA"
         << "|" << setw(18) << "NA"
         << "|" << setw(10) << "NA"
         << "|" << setw(12) << sDol
         << "|" << endl;
}
void XyzEmployee::printEmployeeTypeSummary() const {
    printEmployeeSummary();
}
XyzEmployee::~XyzEmployee() {}