#ifndef XYZ_CONTRACTOR_EMPLOYEE_C
#define XYZ_CONTRACTOR_EMPLOYEE_C
#include "XyzContractorEmployee.H"
#include <iostream>
using namespace std;

XyzContractorEmployee :: XyzContractorEmployee(string nameParm, string idParm,Gender genderParm,Date dobParm, Date dojParm, Agency agencyParm) : XyzEmployee(nameParm, idParm, CONTRACTOR, genderParm, dobParm, dojParm), mAgency(agencyParm) {
}
Agency XyzContractorEmployee :: getAgency() const {
    return mAgency;
}
void XyzContractorEmployee ::  printEmployeeDetails() const {
    XyzEmployee::printEmployeeDetails();
    cout << "Agency: " <<  agencyToString(mAgency) << endl;
}
XyzContractorEmployee :: ~XyzContractorEmployee() {}

#endif