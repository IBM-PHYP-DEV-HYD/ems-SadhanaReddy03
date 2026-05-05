#ifndef XYZ_EMPLOYEE_MANAGER_H
#define XYZ_EMPLOYEE_MANAGER_H

#include "XyzFullTimeEmployee.H"
#include "XyzContractorEmployee.H"
#include "XyzInternEmployee.H"
#include "ExtendedDeque.H"
using namespace std;

class XyzEmployeeManager {
    private : 
        ExtendedDeque<XyzEmployee*> mActiveEmployees;
        ExtendedDeque<XyzEmployee*> mResignedEmployees;
    public:
        XyzEmployeeManager();
        ~XyzEmployeeManager();
        void addEmployee();
        void addLeavesToAllFullTimeEmployees(int leavesParm);
        void convertInternToFullTime(const string& idParm);
        void addEmployee(EmployeeType type);
        bool removeEmployee(const string& idParm);
        void printAllEmployees();
        void printByType(EmployeeType typeParm);
        void printResignedEmployees();
        void printByStatus(EmployeeStatus statusParm);
        void printByGender(Gender genderParm);
        void searchByName(const string& nameParm);
        XyzEmployee* searchByID(const string& idParm);
        
};
#endif