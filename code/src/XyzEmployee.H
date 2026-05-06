#ifndef XYZ_EMPLOYEE_H
#define XYZ_EMPLOYEE_H
#include<iostream>
#include "XyzEmployeeIF.H"
#include "utils.H"
using namespace util;
using namespace std;
class XyzEmployee : public XyzEmployeeIF {
    protected:
        string mName;
        string mID;
        EmployeeType mType;
        Gender mGender;
        EmployeeStatus mStatus;
        Date mDOB;
        Date mDOJ;
        Date mDOL;
    public:
    XyzEmployee(string nameParm, string idParm, EmployeeType typeParm, Gender genderParm, Date dobParm, Date dojParm);
    string getName() const override;
    string getID() const override;
    EmployeeType getType() const override;
    Gender getGender() const override;
    EmployeeStatus getStatus() const override;
    Date getDOB() const override;
    Date getDOJ() const override;
    Date getDOL() const override;

    void setStatus(EmployeeStatus statusParm) override;
    void setDOJ(const Date& dojParm) override;
    void setDOL(const Date& dolParm) override;
    virtual void printEmployeeDetails() const override;
    virtual ~XyzEmployee();
};

#endif