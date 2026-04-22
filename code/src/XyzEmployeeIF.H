#ifndef XYZ_EMPLOYEE_IF_H
#define XYZ_EMPLOYEE_IF_H

#include <string>
#include "utils.H"
using namespace std;
using namespace util;

class XyzEmployeeIF {
public:
    virtual string getName() const = 0;
    virtual string getID() const = 0;
    virtual EmployeeType getType() const = 0;
    virtual Gender getGender() const = 0;
    virtual EmployeeStatus getStatus() const = 0;
    virtual Date getDOB() const = 0;
    virtual Date getDOJ() const = 0;
    virtual Date getDOL() const = 0;

    virtual void setStatus(EmployeeStatus statusParm) = 0;
    virtual void setDOJ(const Date& dojParm) = 0;
    virtual void setDOL(const Date& dolParm) = 0;

    virtual void printEmployeeDetails() const = 0;

    virtual ~XyzEmployeeIF() {}
};

#endif