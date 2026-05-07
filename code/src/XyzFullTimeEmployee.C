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
    cout << "Leaves Availed: " << mLeavesAvailed << endl;
    cout<< "Leaves Left: " << getLeavesLeft() << endl;
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
XyzFullTimeEmployee :: ~XyzFullTimeEmployee() {}
