#include "XyzEmployeeManager.H"
#include "XyzEmployeeFactory.H"
#include <iostream>
#include <random>

using namespace std;
// using namespace util;

//Random Generator
class RandomGenerator {
private:
    mt19937 gen;

public:
    RandomGenerator() {
        random_device rd;
        gen = mt19937(rd());
    }

    int getInt(int low, int high) {
        uniform_int_distribution<int> dist(low, high);
        return dist(gen);
    }
};

static RandomGenerator rng;

XyzEmployeeManager::XyzEmployeeManager() {}

// Destructor
XyzEmployeeManager::~XyzEmployeeManager() {
    while (!mActiveEmployees.empty()) {
        delete mActiveEmployees.front();
        mActiveEmployees.popFront();
    }

    while (!mResignedEmployees.empty()) {
        delete mResignedEmployees.front();
        mResignedEmployees.popFront();
    }
}

void XyzEmployeeManager::addEmployee() {
    static int sCounter = 1;

    EmployeeType sType = (EmployeeType)rng.getInt(1, 3);

    XyzEmployee* sEmp = XyzEmployeeFactory::createEmployee(sCounter, sType);
    sCounter++;

    int sPos = rng.getInt(0, mActiveEmployees.size());
    mActiveEmployees.insertAt(sPos, sEmp);
}


void XyzEmployeeManager::addEmployee(EmployeeType typeParm) {
    static int sCounter = 1;

    XyzEmployee* sEmp = XyzEmployeeFactory::createEmployee(sCounter, typeParm);
    sCounter++;

    int sPos = rng.getInt(0, mActiveEmployees.size());
    mActiveEmployees.insertAt(sPos, sEmp);
}

// Remove employee
bool XyzEmployeeManager::removeEmployee(const string& idParm) {
    for (int sIndex = 0; sIndex < mActiveEmployees.size(); sIndex++) {
        if (idParm == mActiveEmployees[sIndex]->getID()) {
            XyzEmployee* sOld = mActiveEmployees[sIndex];
            XyzEmployee* sMinimal = new XyzEmployee(
                sOld->getName(),
                sOld->getID(),
                sOld->getType(),
                sOld->getGender(),
                sOld->getDOB(),
                sOld->getDOJ()
            );
            sMinimal->setStatus(RESIGNED);
            Date sDol = sOld->getDOJ();
            sDol.mYear += 2;

            sMinimal->setDOL(sDol);
            mResignedEmployees.pushBack(sMinimal);
            delete sOld;
            mActiveEmployees.removeAt(sIndex);
            return true;
        }
    }
    return false;
}

void printSummaryHeader() {
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    cout << "| Employee Name | ID | Type | Status | Gender | Date of Birth | Date of Joining |" << endl;
    cout << "--------------------------------------------------------------------------------------------------" << endl;
}

void XyzEmployeeManager::printAllEmployees() {
    if (mActiveEmployees.size() == 0 && mResignedEmployees.size() == 0) {
        cout << "No employees available.\n";
        return;
    }
    if (mActiveEmployees.size() > 0) {
        cout << "\n--- Active / Inactive Employees ---\n";
        printSummaryHeader();
        for (int sIndex = 0; sIndex < mActiveEmployees.size(); sIndex++) {
            mActiveEmployees[sIndex]->printEmployeeSummary();
        }
    } else {
        cout << "\nNo active/inactive employees.\n";
    }

    if (mResignedEmployees.size() > 0) {
        cout << "\n--- Resigned Employees ---\n";
        printSummaryHeader();
        for (int sIndex = 0; sIndex < mResignedEmployees.size(); sIndex++) {
            mResignedEmployees[sIndex]->printEmployeeSummary();
        }
    } else {
        cout << "\nNo resigned employees.\n";
    }
}

void XyzEmployeeManager::printByType(EmployeeType typeParm) {
    bool sFound = false;
    printSummaryHeader();
    for (int sIndex = 0; sIndex < mActiveEmployees.size(); sIndex++) {
        if (typeParm == mActiveEmployees[sIndex]->getType()){
            mActiveEmployees[sIndex]->printEmployeeSummary();
            sFound = true;
        }
    }
    if(!sFound) {
        cout<<"No employees found for selected type. "<<endl;
    }
}

void XyzEmployeeManager::printByStatus(EmployeeStatus statusParm) {
    bool sFound = false;
    printSummaryHeader();
    for (int sIndex = 0; sIndex < mActiveEmployees.size(); sIndex++) {
        if (statusParm == mActiveEmployees[sIndex]->getStatus()){
            mActiveEmployees[sIndex]->printEmployeeSummary();
            sFound=true;
        }
    }
    if(!sFound) {
        cout<<"No employees found for selected status. "<<endl;
    }
}

void XyzEmployeeManager::printByGender(Gender genderParm) {
    bool sFound = false;
    printSummaryHeader();
    for (int sIndex = 0; sIndex < mActiveEmployees.size(); sIndex++) {
        if (genderParm == mActiveEmployees[sIndex]->getGender()){
            mActiveEmployees[sIndex]->printEmployeeSummary();
            sFound = true;
        }
    }
    if(!sFound) {
        cout<<"No employees found for selected Gender. "<<endl;
    }
}

void XyzEmployeeManager::printResignedEmployees() {
    if (0 == mResignedEmployees.size()) {
        cout << "No resigned employees.\n";
        return;
    }
    printSummaryHeader();
    for (int sIndex = 0; sIndex < mResignedEmployees.size(); sIndex++) {
        mResignedEmployees[sIndex]->printEmployeeSummary();
    }
}

// Search
XyzEmployee* XyzEmployeeManager::searchByID(const string& idParm) {
    for (int sIndex = 0; sIndex < mActiveEmployees.size(); sIndex++) {
        if (idParm == mActiveEmployees[sIndex]->getID())
            return mActiveEmployees[sIndex];
    }
    for(int sIndex = 0; sIndex < mResignedEmployees.size(); sIndex++) {
        if (idParm == mResignedEmployees[sIndex]->getID())
            return mResignedEmployees[sIndex];
    }
    return nullptr;
}


void XyzEmployeeManager::searchByName(const string& nameParm) {
    bool sFound = false;

    for (int sIndex = 0; sIndex < mActiveEmployees.size(); sIndex++) {
        if (mActiveEmployees[sIndex]->getName().find(nameParm) != string::npos) {
            cout << "--------------------------------------\n";
            mActiveEmployees[sIndex]->printEmployeeDetails();
            cout << "--------------------------------------\n";
            sFound = true;
        }
    }

    for (int sIndex = 0; sIndex < mResignedEmployees.size(); sIndex++) {
        if (mResignedEmployees[sIndex]->getName().find(nameParm) != string::npos) {
            cout << "--------------------------------------\n";
            mResignedEmployees[sIndex]->printEmployeeDetails();
            cout << "--------------------------------------\n";
            sFound = true;
        }
    }

    if (!sFound) {
        cout << "No employees found with given name.\n";
    }
}

// Other
void XyzEmployeeManager::addLeavesToAllFullTimeEmployees(int nLeavesParm) {
    if(nLeavesParm<=0) return;
    for (int sIndex = 0; sIndex < mActiveEmployees.size(); sIndex++) {
        if (EmployeeType::FULL_TIME == mActiveEmployees[sIndex]->getType()) {
            XyzFullTimeEmployee* sFullTimeEmp = dynamic_cast<XyzFullTimeEmployee*>(mActiveEmployees[sIndex]);
            if (sFullTimeEmp) sFullTimeEmp->addLeaves(nLeavesParm);
        }
    }
}

void XyzEmployeeManager::convertInternToFullTime(const string& idParm) {
    for (int sIndex = 0; sIndex < mActiveEmployees.size(); sIndex++) {
        if (mActiveEmployees[sIndex]->getID() == idParm &&
            mActiveEmployees[sIndex]->getType() == EmployeeType :: INTERN) {
            XyzInternEmployee* sInternEmp = dynamic_cast<XyzInternEmployee*>(mActiveEmployees[sIndex]);
            if(!sInternEmp) return;

            string sOldID= sInternEmp->getID();
            string sNewID = sOldID.substr(0, sOldID.size() - 1) + "F";


            XyzEmployee* sFullTimeEmp = new XyzFullTimeEmployee(
                sInternEmp->getName(),
                sNewID,
                sInternEmp->getGender(),
                sInternEmp->getDOB(),
                sInternEmp->getDOJ(),
                0
            );
            sFullTimeEmp->setDOL({0,0,0});

            delete sInternEmp;
            mActiveEmployees.removeAt(sIndex);
            mActiveEmployees.insertAt(sIndex,sFullTimeEmp);
            return;
        }
    }
}