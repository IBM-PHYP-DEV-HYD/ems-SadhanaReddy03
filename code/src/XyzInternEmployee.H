#ifndef XYZ_INTERN_EMPLOYEE_H
#define XYZ_INTERN_EMPLOYEE_H
#include "XyzEmployee.H"
#include <iostream>
using namespace std;

class XyzInternEmployee : public XyzEmployee {
    private:
        College mCollege;
        Branch mBranch;
    public:
        XyzInternEmployee(string nameParm, string idParm, Gender genderParm, Date dobParm, Date dojParm, College collegeParm, Branch branchParm) : XyzEmployee(nameParm, idParm, INTERN, genderParm, dobParm, dojParm), mCollege(collegeParm), mBranch(branchParm) {}
        College getCollege() const {
            return mCollege;
        }
        Branch getBranch() const {
            return mBranch;
        }
        void printEmployeeDetails() const override {
            XyzEmployee::printEmployeeDetails();
            cout << "College: " << mCollege << endl;
            cout << "Branch: " << mBranch << endl;
        }
        virtual ~XyzInternEmployee() {}
};

#endif