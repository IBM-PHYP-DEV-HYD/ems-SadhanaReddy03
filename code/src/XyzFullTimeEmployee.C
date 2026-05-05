#ifndef XYZ_FULLTIME_EMPLOYEE_C
#define XYZ_FULLTIME_EMPLOYEE_C
#include "XyzFullTimeEmployee.H"
#include <iostream>
using namespace std;

XyzFullTimeEmployee :: XyzFullTimeEmployee(string nameParm, string idParm, Gender genderParm, Date dobParm, Date dojParm, int leavesParm) : XyzEmployee(nameParm, idParm, FULL_TIME, genderParm, dobParm, dojParm), mLeavesAvailed(leavesParm) {}
void XyzFullTimeEmployee :: addLeaves(int leavesParm) {
    if(leavesParm <= 0) return;
    mLeavesAvailed += leavesParm;
    if(mLeavesAvailed > 22) {
        mLeavesAvailed = 22;  
    }
}
void XyzFullTimeEmployee :: printEmployeeDetails() const{
    XyzEmployee::printEmployeeDetails();
    cout << "Leaves Availed: " << mLeavesAvailed << endl;
    cout<< "Leaves Left: " << (22 - mLeavesAvailed) << endl;
}
int XyzFullTimeEmployee :: getLeavesAvailed() const {
    return mLeavesAvailed;
}
XyzFullTimeEmployee :: ~XyzFullTimeEmployee() {}

#endif
