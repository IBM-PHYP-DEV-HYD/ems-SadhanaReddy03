#include "XyzEmployeeManager.H"
#include "XyzEmployeeFactory.H"
#include <iostream>
#include <random>

using namespace std;
using namespace util;

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
    static int counter = 1;

    EmployeeType type = (EmployeeType)rng.getInt(1, 3);

    XyzEmployee* emp = XyzEmployeeFactory::createEmployee(counter, type);
    counter++;

    int pos = rng.getInt(0, mActiveEmployees.size());
    mActiveEmployees.insertAt(pos, emp);
}


void XyzEmployeeManager::addEmployee(EmployeeType type) {
    static int counter = 1;

    XyzEmployee* emp = XyzEmployeeFactory::createEmployee(counter, type);
    counter++;

    int pos = rng.getInt(0, mActiveEmployees.size());
    mActiveEmployees.insertAt(pos, emp);
}

// Remove employee
bool XyzEmployeeManager::removeEmployee(const string& idParm) {
    for (int i = 0; i < mActiveEmployees.size(); i++) {
        if (mActiveEmployees[i]->getID() == idParm) {
            XyzEmployee* old = mActiveEmployees[i];
            XyzEmployee* minimal = new XyzEmployee(
                old->getName(),
                old->getID(),
                old->getType(),
                old->getGender(),
                old->getDOB(),
                old->getDOJ()
            );
            minimal->setStatus(RESIGNED);
            Date dol = old->getDOJ();
            dol.year += 2;

            minimal->setDOL(dol);
            mResignedEmployees.pushBack(minimal);
            delete old;
            mActiveEmployees.removeAt(i);
            return true;
        }
    }
    return false;
}


void XyzEmployeeManager::printAllEmployees() {
    if (mActiveEmployees.size() == 0 && mResignedEmployees.size() == 0) {
        cout << "No employees available.\n";
        return;
    }
    if (mActiveEmployees.size() > 0) {
        cout << "\n--- Active / Inactive Employees ---\n";
        for (int i = 0; i < mActiveEmployees.size(); i++) {
            mActiveEmployees[i]->printEmployeeDetails();
            cout << "----------------\n";
        }
    } else {
        cout << "\nNo active/inactive employees.\n";
    }

    if (mResignedEmployees.size() > 0) {
        cout << "\n--- Resigned Employees ---\n";
        for (int i = 0; i < mResignedEmployees.size(); i++) {
            mResignedEmployees[i]->printEmployeeDetails();
            cout << "----------------\n";
        }
    } else {
        cout << "\nNo resigned employees.\n";
    }
}

void XyzEmployeeManager::printByType(EmployeeType typeParm) {
    bool found = false;

    for (int i = 0; i < mActiveEmployees.size(); i++) {
        if (mActiveEmployees[i]->getType() == typeParm){
            mActiveEmployees[i]->printEmployeeDetails();
            cout<<"--------------------------"<<endl;
            found = true;
        }
    }
    if(!found) {
        cout<<"No employees found for selected type. "<<endl;
    }
}

void XyzEmployeeManager::printByStatus(EmployeeStatus statusParm) {
    bool found = false;
    for (int i = 0; i < mActiveEmployees.size(); i++) {
        if (mActiveEmployees[i]->getStatus() == statusParm){
            mActiveEmployees[i]->printEmployeeDetails();
            cout<<"---------------------------"<<endl;
            found=true;
        }
    }
    if(!found) {
        cout<<"No employees found for selected status. "<<endl;
    }
}

void XyzEmployeeManager::printByGender(Gender genderParm) {
    bool found = false;
    for (int i = 0; i < mActiveEmployees.size(); i++) {
        if (mActiveEmployees[i]->getGender() == genderParm){
            mActiveEmployees[i]->printEmployeeDetails();
            cout<<"--------------------------------------"<<endl;
            found = true;
        }
    }
    if(!found) {
        cout<<"No employees found for selected Gender. "<<endl;
    }
}

void XyzEmployeeManager::printResignedEmployees() {
    if (mResignedEmployees.size() == 0) {
        cout << "No resigned employees.\n";
        return;
    }
    for (int i = 0; i < mResignedEmployees.size(); i++) {
        mResignedEmployees[i]->printEmployeeDetails();
    }
}

// Search
XyzEmployee* XyzEmployeeManager::searchByID(const string& idParm) {
    for (int i = 0; i < mActiveEmployees.size(); i++) {
        if (mActiveEmployees[i]->getID() == idParm)
            return mActiveEmployees[i];
    }
    for(int i = 0; i < mResignedEmployees.size(); i++) {
        if (mResignedEmployees[i]->getID() == idParm)
            return mResignedEmployees[i];
    }
    return nullptr;
}


void XyzEmployeeManager::searchByName(const string& nameParm) {
    bool found = false;

    for (int i = 0; i < mActiveEmployees.size(); i++) {
        if (mActiveEmployees[i]->getName().find(nameParm) != string::npos) {
            mActiveEmployees[i]->printEmployeeDetails();
            cout << "----------------\n";
            found = true;
        }
    }

    for (int i = 0; i < mResignedEmployees.size(); i++) {
        if (mResignedEmployees[i]->getName().find(nameParm) != string::npos) {
            mResignedEmployees[i]->printEmployeeDetails();
            cout << "----------------\n";
            found = true;
        }
    }

    if (!found) {
        cout << "No employees found with given name.\n";
    }
}

// Other
void XyzEmployeeManager::addLeavesToAllFullTimeEmployees(int n) {
    if(n<=0) return;
    for (int i = 0; i < mActiveEmployees.size(); i++) {
        if (mActiveEmployees[i]->getType() == FULL_TIME) {
            auto ft = dynamic_cast<XyzFullTimeEmployee*>(mActiveEmployees[i]);
            if (ft) ft->addLeaves(n);
        }
    }
}

void XyzEmployeeManager::convertInternToFullTime(const string& idParm) {
    for (int i = 0; i < mActiveEmployees.size(); i++) {
        if (mActiveEmployees[i]->getID() == idParm &&
            mActiveEmployees[i]->getType() == INTERN) {

            auto intern = dynamic_cast<XyzInternEmployee*>(mActiveEmployees[i]);
            if(!intern) return;

            string oldID= intern->getID();
            string newID = oldID.substr(0, oldID.size() - 1) + "F";


            XyzEmployee* ft = new XyzFullTimeEmployee(
                intern->getName(),
                newID,
                intern->getGender(),
                intern->getDOB(),
                intern->getDOJ(),
                0
            );
            ft->setDOL({0,0,0});

            delete intern;
            mActiveEmployees.removeAt(i);
            mActiveEmployees.insertAt(i,ft);
            return;
        }
    }
}