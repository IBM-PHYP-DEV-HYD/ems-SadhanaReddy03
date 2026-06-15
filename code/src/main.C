#include "XyzEmployeeManager.H"
#include "utils.H"
#include <iostream>

using namespace std;

void displayMainMenu() {
    cout << "\n========================================" << endl;
    cout << "   XYZ CORPORATION - EMPLOYEE MANAGER" << endl;
    cout << "========================================" << endl;
    cout << "1. Add an Employee" << endl;
    cout << "2. Remove an Employee" << endl;
    cout << "3. Employee Details" << endl;
    cout << "4. Others" << endl;
    cout << "5. Exit" << endl;
    cout << "========================================" << endl;
    cout << "Enter your choice: ";
}

void displayAddMenu() {
    cout << "\n--- Add Employee Menu ---" << endl;
    cout << "1. Add an Employee at Random" << endl;
    cout << "2. Add Employee (F/C/I)" << endl;
    cout << "3. Back to Main Menu" << endl;
    cout << "Enter your choice: ";
}

void displayDetailsMenu() {
    cout<<"\n--- Employee Details Menu ---"<<endl;
    cout<<"1. All Employees Summary"<<endl;
    cout<<"2. Employee Summary by Type"<<endl;
    cout<<"3. Employee Summary by Gender"<<endl;
    cout<<"4. Employee Summary by Status"<<endl;
    cout<<"5. Display Employee Details by ID"<<endl;
    cout<<"6. Back to Main Menu"<<endl;
    cout<<"Enter your choice: ";
}
void displayOthersMenu() {
    cout<<"\n--- Others Menu ---"<<endl;
    cout<<"1. Add 'n' number of leaves to all Full-Time employees"<<endl;
    cout<<"2. Convert an Intern to Full-Time employee"<<endl;
    cout<<"3. Search an Employee by ID"<<endl;
    cout<<"4. Search an Employee by Name"<<endl;
    cout<<"5. Back to Main Menu"<<endl;
    cout<<"Enter your choice: ";
}

// Handlers
void handleAddMenu(XyzEmployeeManager& managerParm) {
    int sChoice;

    while (true) {
        displayAddMenu();
        readValue(sChoice, "Enter valid choice: ");

        switch (sChoice) {
            case AddMenu :: ADD_RANDOM:
                managerParm.addEmployee();
                cout << "Employee added successfully.\n";
                break;

            case AddMenu :: ADD_TYPE: {
                int sType;
                cout << "Enter Type (1-FullTime, 2-Contractor, 3-Intern): ";
                readValue(sType, "Enter 1-3 only: ");
                managerParm.addEmployee((EmployeeType)sType);
                cout << "Employee added successfully.\n";
                break;
            }

            case AddMenu :: ADD_BACK:
                return;

            default:
                cout << "Invalid choice!\n";
        }
    }
}

void handleDetailsMenu(XyzEmployeeManager& managerParm) {
    int sChoice;

    while (true) {
        displayDetailsMenu();
        readValue(sChoice, "Enter valid choice: ");

        switch (sChoice) {
            case DetailsMenu :: ALL_EMP:
                managerParm.printAllEmployees();
                break;

            case DetailsMenu :: BY_TYPE: {
                int sType;
                cout << "Enter Type (1-FullTime, 2-Contractor, 3-Intern): ";
                readValue(sType, "Enter 1-3 only: ");
                managerParm.printByType((EmployeeType)sType);
                break;
            }

            case DetailsMenu :: BY_GENDER: {
                int sGender;
                cout << "Enter Gender (1-Male, 2-Female): ";
                readValue(sGender, "Enter 1 or 2: ");
                managerParm.printByGender((Gender)sGender);
                break;
            }

            case DetailsMenu :: BY_STATUS: {
                int mStatus;
                cout << "Enter Status (1-Active, 2-Inactive, 3-Resigned): ";
                readValue(mStatus, "Enter 1-3: ");

                if (util :: RESIGNED == mStatus)
                    managerParm.printResignedEmployees();
                else
                    managerParm.printByStatus((EmployeeStatus)mStatus);
                break;
            }

            case DetailsMenu :: BY_ID: {
                string sId;
                cout << "Enter Employee ID: ";
                getline(cin >> ws, sId);

                XyzEmployee* sEmp = managerParm.searchByID(sId);
                if (sEmp)
                    sEmp->printEmployeeDetails();
                else
                    cout << "Employee not found.\n";
                break;
            }

            case DetailsMenu :: DETAILS_BACK:
                return;

            default:
                cout << "Invalid choice!\n";
        }
    }
}

void handleOthersMenu(XyzEmployeeManager& managerParm) {
    int sChoice;

    while (true) {
        displayOthersMenu();
        readValue(sChoice, "Enter valid choice: ");

        switch (sChoice) {
            case OthersMenu:: ADD_LEAVES: {
                int sNLeaves;
                cout << "Enter leaves to add: ";
                readValue(sNLeaves, "Enter positive number: ");
                managerParm.addLeavesToAllFullTimeEmployees(sNLeaves);
                break;
            }

            case OthersMenu :: CONVERT_INTERN: {
                string sId;
                cout << "Enter Intern ID: ";
                getline(cin >> ws, sId);
                managerParm.convertInternToFullTime(sId);
                break;
            }

            case OthersMenu :: SEARCH_ID: {
                string sId;
                cout << "Enter Employee ID: ";
                getline(cin >> ws, sId);

                XyzEmployee* sEmp = managerParm.searchByID(sId);
                if (sEmp)
                    sEmp->printEmployeeDetails();
                else
                    cout << "Employee not found.\n";
                break;
            }

            case OthersMenu :: SEARCH_NAME: {
                string sName;
                cout << "Enter Name: ";
                getline(cin >> ws, sName);
                managerParm.searchByName(sName);
                break;
            }

            case OthersMenu :: OTHERS_BACK:
                return;

            default:
                cout << "Invalid choice!\n";
        }
    }
}

// Main
int main() {
    XyzEmployeeManager managerParm;
    int sChoice;

    while (true) {
        displayMainMenu();
        readValue(sChoice, "Enter valid choice: ");

        switch (sChoice) {
            case MainMenu :: ADD_EMP:
                handleAddMenu(managerParm);
                break;

            case MainMenu :: REMOVE_EMP: {
                string sId;
                cout << "Enter Employee ID: ";
                getline(cin >> ws, sId);

                if (managerParm.removeEmployee(sId))
                    cout << "Employee removed.\n";
                else
                    cout << "Employee not found.\n";
                break;
            }

            case MainMenu :: EMP_DETAILS:
                handleDetailsMenu(managerParm);
                break;

            case MainMenu :: OTHERS:
                handleOthersMenu(managerParm);
                break;

            case MainMenu :: EXIT_APP:
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
}