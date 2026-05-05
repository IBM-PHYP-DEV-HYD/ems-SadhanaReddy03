#ifndef XYZ_FULLTIME_EMPLOYEE_H
#define XYZ_FULLTIME_EMPLOYEE_H
#include "XyzEmployee.H"
#include <iostream>
using namespace std;
class XyzFullTimeEmployee : public XyzEmployee {
    private:
    int mLeavesAvailed;
    public:
    XyzFullTimeEmployee(string nameParm, string idParm, Gender genderParm, Date dobParm, Date dojParm, int leavesParm);
    void addLeaves(int leavesParm);
    void printEmployeeDetails() const override ;
    int getLeavesAvailed() const;
    virtual ~XyzFullTimeEmployee();
};
#endif