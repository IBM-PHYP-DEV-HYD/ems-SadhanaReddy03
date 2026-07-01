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
    cout << "External Agency : " <<  agencyToString(mAgency) << endl;
}
void XyzContractorEmployee::printEmployeeSummary() const {

    string sDob = to_string(mDOB.mDay) + "/" +
                  to_string(mDOB.mMonth) + "/" +
                  to_string(mDOB.mYear);

    string sDoj = to_string(mDOJ.mDay) + "/" +
                  to_string(mDOJ.mMonth) + "/" +
                  to_string(mDOJ.mYear);

    string sDol = "NA";

    if (mDOL.mYear != 0) {
        sDol = to_string(mDOL.mDay) + "/" +
               to_string(mDOL.mMonth) + "/" +
               to_string(mDOL.mYear);
    }

    cout << left
         << "|" << setw(12) << mName
         << "|" << setw(12) << mID
         << "|" << setw(12) << typeToString(mType)
         << "|" << setw(12) << statusToString(mStatus)
         << "|" << setw(10) << genderToString(mGender)
         << "|" << setw(12) << sDob
         << "|" << setw(12) << sDoj
         << "|" << setw(15) << "NA"
         << "|" << setw(12) << "NA"
         << "|" << setw(18) << agencyToString(mAgency)
         << "|" << setw(18) << "NA"
         << "|" << setw(10) << "NA"
         << "|" << setw(12) << sDol
         << "|" << endl;
}
void XyzContractorEmployee::printEmployeeTypeSummary() const {

    string sDob = to_string(mDOB.mDay) + "/" +
                  to_string(mDOB.mMonth) + "/" +
                  to_string(mDOB.mYear);

    string sDoj = to_string(mDOJ.mDay) + "/" +
                  to_string(mDOJ.mMonth) + "/" +
                  to_string(mDOJ.mYear);

    string sDol = "NA";

    if (mDOL.mYear != 0) {
        sDol = to_string(mDOL.mDay) + "/" +
               to_string(mDOL.mMonth) + "/" +
               to_string(mDOL.mYear);
    }

    cout << left
         << "|" << setw(12) << mName
         << "|" << setw(12) << mID
         << "|" << setw(12) << typeToString(mType)
         << "|" << setw(12) << statusToString(mStatus)
         << "|" << setw(10) << genderToString(mGender)
         << "|" << setw(12) << sDob
         << "|" << setw(12) << sDoj
         << "|" << setw(18) << agencyToString(mAgency)
         << "|" << setw(12) << sDol
         << "|" << endl;
}
XyzContractorEmployee :: ~XyzContractorEmployee() {}
