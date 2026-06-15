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
    static XyzEmployee* createEmployee(int counterParm, EmployeeType typeParm) {
        Gender sGender = (Gender)getInt(1,2);

        Date sDob = getRandomDate();
        Date sDoj = sDob;
        sDoj.mYear += getInt(20,30);

        string sId = "XYZ";
        string sNum = to_string(counterParm);
        while (sNum.length() < 4) sNum = "0" + sNum;
        sId += sNum;

        if (EmployeeType::FULL_TIME == typeParm) sId += "F";
        else if (EmployeeType::CONTRACTOR == typeParm) sId += "C";
        else sId += "I";

        string sName = "Emp" + to_string(counterParm);

        XyzEmployee* sEmp = nullptr;

        if (EmployeeType::FULL_TIME == typeParm) {
            int sLeaves = getInt(0,22);
            sEmp = new XyzFullTimeEmployee(sName, sId, sGender, sDob, sDoj, sLeaves);
        }
        else if (EmployeeType::CONTRACTOR == typeParm) {
            Agency sAgency = (Agency)getInt(1,3);
            sEmp = new XyzContractorEmployee(sName, sId, sGender, sDob, sDoj, sAgency);

            Date sDol = sDoj;
            sDol.mYear += 1;
            sEmp->setDOL(sDol);
        }
        else {
            College sCollege = (College)getInt(1,7);
            Branch sBranch = (Branch)getInt(1,3);
            sEmp = new XyzInternEmployee(sName, sId, sGender, sDob, sDoj, sCollege, sBranch);

            Date sDol = sDoj;
            sDol.mMonth += 6;
            if (sDol.mMonth > 12) {
                sDol.mMonth -= 12;
                sDol.mYear += 1;
            }
            sEmp->setDOL(sDol);
        }

        EmployeeStatus sStatus = (EmployeeStatus)getInt(1,2); // ACTIVE/INACTIVE
        sEmp->setStatus(sStatus);

        return sEmp;
    }
};

#endif