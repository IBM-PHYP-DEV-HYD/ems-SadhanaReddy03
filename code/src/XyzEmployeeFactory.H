#ifndef XYZ_EMPLOYEE_FACTORY_H
#define XYZ_EMPLOYEE_FACTORY_H

#include "XyzFullTimeEmployee.H"
#include "XyzContractorEmployee.H"
#include "XyzInternEmployee.H"
#include "utils.H"
#include <random>

using namespace util;
using namespace std;

class XyzEmployeeFactory {
private:
    static mt19937& getGenerator() {
        static random_device rd;
        static mt19937 gen(rd());
        return gen;
    }

    static int getInt(int low, int high) {
        uniform_int_distribution<int> dist(low, high);
        return dist(getGenerator());
    }

    static Date getRandomDate() {
        return { getInt(1,28), getInt(1,12), getInt(1995,2020) };
    }

public:
    static XyzEmployee* createEmployee(int counter, EmployeeType type) {
        Gender gender = (Gender)getInt(1,2);

        Date dob = getRandomDate();
        Date doj = dob;
        doj.year += getInt(20,30);

        string id = "XYZ";
        string num = to_string(counter);
        while (num.length() < 4) num = "0" + num;
        id += num;

        if (type == FULL_TIME) id += "F";
        else if (type == CONTRACTOR) id += "C";
        else id += "I";

        string name = "Emp" + to_string(counter);

        XyzEmployee* emp = nullptr;

        if (type == FULL_TIME) {
            int leaves = getInt(0,22);
            emp = new XyzFullTimeEmployee(name, id, gender, dob, doj, leaves);
        }
        else if (type == CONTRACTOR) {
            Agency agency = (Agency)getInt(1,3);
            emp = new XyzContractorEmployee(name, id, gender, dob, doj, agency);

            Date dol = doj;
            dol.year += 1;
            emp->setDOL(dol);
        }
        else {
            College college = (College)getInt(1,7);
            Branch branch = (Branch)getInt(1,3);
            emp = new XyzInternEmployee(name, id, gender, dob, doj, college, branch);

            Date dol = doj;
            dol.month += 6;
            if (dol.month > 12) {
                dol.month -= 12;
                dol.year += 1;
            }
            emp->setDOL(dol);
        }

        EmployeeStatus status = (EmployeeStatus)getInt(1,2); // ACTIVE/INACTIVE
        emp->setStatus(status);

        return emp;
    }
};

#endif