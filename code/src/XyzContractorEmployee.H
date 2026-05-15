#ifndef XYZ_CONTRACTOR_EMPLOYEE_H
#define XYZ_CONTRACTOR_EMPLOYEE_H
#include "XyzEmployee.H"
#include <iostream>

class XyzContractorEmployee : public XyzEmployee {
    private:
        Agency mAgency;
    public:
        XyzContractorEmployee(string nameParm, string idParm,Gender genderParm,Date dobParm, Date dojParm, Agency agencyParm);
        Agency getAgency() const ;
        void printEmployeeDetails() const override;
        virtual ~XyzContractorEmployee();
};
#endif