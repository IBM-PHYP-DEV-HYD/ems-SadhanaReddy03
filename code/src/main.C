#include "XyzEmployeeManager.H"
#include "utils.H"
#include <iostream>

using namespace std;
using namespace util;

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
void handleAddMenu(XyzEmployeeManager& manager) {
    int choice;

    while (true) {
        displayAddMenu();
        readValue(choice, "Enter valid choice: ");

        switch (choice) {
            case ADD_RANDOM:
                manager.addEmployee();
                cout << "Employee added successfully.\n";
                break;

            case ADD_TYPE: {
                int type;
                cout << "Enter Type (1-FullTime, 2-Contractor, 3-Intern): ";
                readValue(type, "Enter 1-3 only: ");
                manager.addEmployee((EmployeeType)type);
                cout << "Employee added successfully.\n";
                break;
            }

            case ADD_BACK:
                return;

            default:
                cout << "Invalid choice!\n";
        }
    }
}

void handleDetailsMenu(XyzEmployeeManager& manager) {
    int choice;

    while (true) {
        displayDetailsMenu();
        readValue(choice, "Enter valid choice: ");

        switch (choice) {
            case ALL_EMP:
                manager.printAllEmployees();
                break;

            case BY_TYPE: {
                int type;
                cout << "Enter Type (1-FullTime, 2-Contractor, 3-Intern): ";
                readValue(type, "Enter 1-3 only: ");
                manager.printByType((EmployeeType)type);
                break;
            }

            case BY_GENDER: {
                int gender;
                cout << "Enter Gender (1-Male, 2-Female): ";
                readValue(gender, "Enter 1 or 2: ");
                manager.printByGender((Gender)gender);
                break;
            }

            case BY_STATUS: {
                int status;
                cout << "Enter Status (1-Active, 2-Inactive, 3-Resigned): ";
                readValue(status, "Enter 1-3: ");

                if (status == RESIGNED)
                    manager.printResignedEmployees();
                else
                    manager.printByStatus((EmployeeStatus)status);
                break;
            }

            case BY_ID: {
                string id;
                cout << "Enter Employee ID: ";
                getline(cin >> ws, id);

                XyzEmployee* emp = manager.searchByID(id);
                if (emp)
                    emp->printEmployeeDetails();
                else
                    cout << "Employee not found.\n";
                break;
            }

            case DETAILS_BACK:
                return;

            default:
                cout << "Invalid choice!\n";
        }
    }
}

void handleOthersMenu(XyzEmployeeManager& manager) {
    int choice;

    while (true) {
        displayOthersMenu();
        readValue(choice, "Enter valid choice: ");

        switch (choice) {
            case ADD_LEAVES: {
                int n;
                cout << "Enter leaves to add: ";
                readValue(n, "Enter positive number: ");
                manager.addLeavesToAllFullTimeEmployees(n);
                break;
            }

            case CONVERT_INTERN: {
                string id;
                cout << "Enter Intern ID: ";
                getline(cin >> ws, id);
                manager.convertInternToFullTime(id);
                break;
            }

            case SEARCH_ID: {
                string id;
                cout << "Enter Employee ID: ";
                getline(cin >> ws, id);

                XyzEmployee* emp = manager.searchByID(id);
                if (emp)
                    emp->printEmployeeDetails();
                else
                    cout << "Employee not found.\n";
                break;
            }

            case SEARCH_NAME: {
                string name;
                cout << "Enter Name: ";
                getline(cin >> ws, name);
                manager.searchByName(name);
                break;
            }

            case OTHERS_BACK:
                return;

            default:
                cout << "Invalid choice!\n";
        }
    }
}

// Main
int main() {
    XyzEmployeeManager manager;
    int choice;

    while (true) {
        displayMainMenu();
        readValue(choice, "Enter valid choice: ");

        switch (choice) {
            case ADD_EMP:
                handleAddMenu(manager);
                break;

            case REMOVE_EMP: {
                string id;
                cout << "Enter Employee ID: ";
                getline(cin >> ws, id);

                if (manager.removeEmployee(id))
                    cout << "Employee removed.\n";
                else
                    cout << "Employee not found.\n";
                break;
            }

            case EMP_DETAILS:
                handleDetailsMenu(manager);
                break;

            case OTHERS:
                handleOthersMenu(manager);
                break;

            case EXIT_APP:
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
}