#include "XyzFullTimeEmployee.H"
#include <iostream>
using namespace std;

XyzFullTimeEmployee :: XyzFullTimeEmployee(string nameParm, string idParm, Gender genderParm, Date dobParm, Date dojParm, int leavesParm) : XyzEmployee(nameParm, idParm, FULL_TIME, genderParm, dobParm, dojParm), mLeavesAvailed(leavesParm), mTotalLeaves(22) {}
void XyzFullTimeEmployee :: addLeaves(int leavesParm) {
    if(leavesParm <= 0) return;
    mTotalLeaves += leavesParm;
}
void XyzFullTimeEmployee :: printEmployeeDetails() const{
    XyzEmployee::printEmployeeDetails();
    cout << "Leaves Availed : " << mLeavesAvailed << endl;
    cout<< "Leaves Left    : " << getLeavesLeft() << endl;
    cout<< "Total Leaves: " << mTotalLeaves << endl;
}
int XyzFullTimeEmployee :: getLeavesAvailed() const {
    return mLeavesAvailed;
}
int XyzFullTimeEmployee :: getTotalLeaves() const {
    return mTotalLeaves;
}
int XyzFullTimeEmployee :: getLeavesLeft() const {
    return mTotalLeaves-mLeavesAvailed;
}
void XyzFullTimeEmployee::printEmployeeSummary() const {

    string sDob = to_string(mDOB.mDay) + "/" +
                  to_string(mDOB.mMonth) + "/" +
                  to_string(mDOB.mYear);

    string sDoj = to_string(mDOJ.mDay) + "/" +
                  to_string(mDOJ.mMonth) + "/" +
                  to_string(mDOJ.mYear);

    cout << left
         << "|" << setw(12) << mName
         << "|" << setw(12) << mID
         << "|" << setw(12) << typeToString(mType)
         << "|" << setw(12) << statusToString(mStatus)
         << "|" << setw(10) << genderToString(mGender)
         << "|" << setw(12) << sDob
         << "|" << setw(12) << sDoj
         << "|" << setw(15) << mLeavesAvailed
         << "|" << setw(12) << getLeavesLeft()
         << "|" << setw(18) << "NA"
         << "|" << setw(18) << "NA"
         << "|" << setw(10) << "NA"
         << "|" << setw(12) << "NA"
         << "|" << endl;
}
void XyzFullTimeEmployee::printEmployeeTypeSummary() const {

    string sDob = to_string(mDOB.mDay) + "/" +
                  to_string(mDOB.mMonth) + "/" +
                  to_string(mDOB.mYear);

    string sDoj = to_string(mDOJ.mDay) + "/" +
                  to_string(mDOJ.mMonth) + "/" +
                  to_string(mDOJ.mYear);

    cout << left
         << "|" << setw(12) << mName
         << "|" << setw(12) << mID
         << "|" << setw(12) << typeToString(mType)
         << "|" << setw(12) << statusToString(mStatus)
         << "|" << setw(10) << genderToString(mGender)
         << "|" << setw(12) << sDob
         << "|" << setw(12) << sDoj
         << "|" << setw(15) << mLeavesAvailed
         << "|" << setw(12) << getLeavesLeft()
         << "|" << endl;
}
XyzFullTimeEmployee :: ~XyzFullTimeEmployee() {}
