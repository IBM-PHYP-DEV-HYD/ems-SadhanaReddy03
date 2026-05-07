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
    cout << "College: " << collegeToString(mCollege) << endl;
    cout << "Branch: " << branchToString(mBranch) << endl;
}
XyzInternEmployee :: ~XyzInternEmployee() {}
