#ifndef XYZ_FULLTIME_EMPLOYEE_H
#define XYZ_FULLTIME_EMPLOYEE_H
#include "XyzEmployee.H"
#include <iostream>
using namespace std;
class XyzFullTimeEmployee : public XyzEmployee {
    private:
    int mLeavesAvailed;
    public:
    XyzFullTimeEmployee(string nameParm, string idParm, Gender genderParm, Date dobParm, Date dojParm) : XyzEmployee(nameParm, idParm, FULL_TIME, genderParm, dobParm, dojParm), mLeavesAvailed(0) {
    }
    void addLeaves(int leavesParm) {
        mLeavesAvailed += leavesParm;
        if(mLeavesAvailed > 22) {
            mLeavesAvailed = 22;  
        }
    }
    void printEmployeeDetails() const override {
        XyzEmployee::printEmployeeDetails();
        cout << "Leaves Availed: " << mLeavesAvailed << endl;
        cout<< "Leaves Left: " << (22 - mLeavesAvailed) << endl;
    }
    virtual ~XyzFullTimeEmployee() {}
};



#endif