#ifndef XYZ_FULLTIME_EMPLOYEE_H
#define XYZ_FULLTIME_EMPLOYEE_H
#include "XyzEmployee.H"
#include <iostream>
using namespace std;
class XyzFullTimeEmployee : public XyzEmployee {
    private:
    int mLeavesAvailed;
    int mTotalLeaves;
    public:
    XyzFullTimeEmployee(string nameParm, string idParm, Gender genderParm, Date dobParm, Date dojParm, int leavesParm);
    void addLeaves(int leavesParm);
    void printEmployeeDetails() const override ;
    void printEmployeeSummary() const override ;
    int getLeavesAvailed() const;
    int getTotalLeaves() const;
    int getLeavesLeft() const;
    virtual ~XyzFullTimeEmployee();
};
#endif