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
        XyzInternEmployee(string nameParm, string idParm, Gender genderParm, Date dobParm, Date dojParm, College collegeParm, Branch branchParm);
        College getCollege() const;
        Branch getBranch() const;
        void printEmployeeDetails() const override;
        void printEmployeeSummary() const override ;
        virtual ~XyzInternEmployee();
};
#endif