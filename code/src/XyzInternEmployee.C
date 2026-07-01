#include "XyzEmployee.H"
#include "XyzInternEmployee.H"
#include <iostream>
using namespace std;


XyzInternEmployee :: XyzInternEmployee(string nameParm, string idParm, Gender genderParm, Date dobParm, Date dojParm, College collegeParm, Branch branchParm) : XyzEmployee(nameParm, idParm, INTERN, genderParm, dobParm, dojParm), mCollege(collegeParm), mBranch(branchParm) {}
College XyzInternEmployee :: getCollege() const {
    return mCollege;
}
Branch XyzInternEmployee :: getBranch() const {
    return mBranch;
}
void XyzInternEmployee :: printEmployeeDetails() const {
    XyzEmployee::printEmployeeDetails();
    cout << "College : " << collegeToString(mCollege) << endl;
    cout << "Branch  : " << branchToString(mBranch) << endl;
}

void XyzInternEmployee::printEmployeeSummary() const {

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
         << "|" << setw(18) << collegeToString(mCollege)
         << "|" << setw(10) << branchToString(mBranch)
         << "|" << setw(12) << sDol
         << "|" << endl;
}
void XyzInternEmployee::printEmployeeTypeSummary() const {

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
         << "|" << setw(18) << collegeToString(mCollege)
         << "|" << setw(10) << branchToString(mBranch)
         << "|" << setw(12) << sDol
         << "|" << endl;
}
XyzInternEmployee :: ~XyzInternEmployee() {}
