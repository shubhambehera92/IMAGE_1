#include <iostream>
#include <string>
using namespace std;

struct Company
{
    string name;
    string location;
    int employees;
    Company* next;
};

Company* head = NULL;

// Create list of N companies
void createList()
{
    int n;

    cout << "\nEnter number of companies: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        Company* newNode = new Company;

        cout << "\nEnter details of Company " << i + 1 << ":\n";

        cout << "Company Name: ";
        cin >> newNode->name;

        cout << "Location: ";
        cin >> newNode->location;

        cout << "Number of Employees: ";
        cin >> newNode->employees;

        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Company* temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    cout << "\nCompany list created successfully!\n";
}

// Append a new company
void appendCompany()
{
    Company* newNode = new Company;

    cout << "\nEnter company details:\n";

    cout << "Company Name: ";
    cin >> newNode->name;

    cout << "Location: ";
    cin >> newNode->location;

    cout << "Number of Employees: ";
    cin >> newNode->employees;

    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Company* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    cout << "\nCompany appended successfully!\n";
}

// Add company at beginning
void addBeginning()
{
    Company* newNode = new Company;

    cout << "\nEnter company details:\n";

    cout << "Company Name: ";
    cin >> newNode->name;

    cout << "Location: ";
    cin >> newNode->location;

    cout << "Number of Employees: ";
    cin >> newNode->employees;

    newNode->next = head;
    head = newNode;

    cout << "\nCompany added at beginning successfully!\n";
}

// Find number of employees
void findEmployees()
{
    string companyName;

    cout << "\nEnter company name: ";
    cin >> companyName;

    Company* temp = head;

    while (temp != NULL)
    {
        if (temp->name == companyName)
        {
            cout << "Number of Employees: "
                 << temp->employees << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Company not found!\n";
}

// Find location
void findLocation()
{
    string companyName;

    cout << "\nEnter company name: ";
    cin >> companyName;

    Company* temp = head;

    while (temp != NULL)
    {
        if (temp->name == companyName)
        {
            cout << "Location: "
                 << temp->location << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Company not found!\n";
}

// Display all companies
void display()
{
    if (head == NULL)
    {
        cout << "\nList is empty!\n";
        return;
    }

    Company* temp = head;

    cout << "\n----- Company List -----\n";

    while (temp != NULL)
    {
        cout << "Company Name: " << temp->name << endl;
        cout << "Location: " << temp->location << endl;
        cout << "Employees: " << temp->employees << endl;
        cout << "------------------------\n";

        temp = temp->next;
    }
}

int main()
{
    int choice;

    // Menu displayed ONLY ONCE
    cout << "========== MENU ==========\n";
    cout << "1. Create list of N companies\n";
    cout << "2. Append a new company\n";
    cout << "3. Add company at beginning\n";
    cout << "4. Find number of employees\n";
    cout << "5. Find location\n";
    cout << "6. Display all companies\n";
    cout << "7. Exit\n";
    cout << "==========================\n";

    do
    {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                createList();
                break;

            case 2:
                appendCompany();
                break;

            case 3:
                addBeginning();
                break;

            case 4:
                findEmployees();
                break;

            case 5:
                findLocation();
                break;

            case 6:
                display();
                break;

            case 7:
                cout << "\nProgram terminated.\n";
                break;

            default:
                cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 7);

    return 0;
}