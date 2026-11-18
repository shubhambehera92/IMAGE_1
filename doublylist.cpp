#include <iostream>
#include <string>
using namespace std;

// Node structure
struct Doctor
{
    string name;
    string specialization;
    string phone;
    Doctor* prev;
    Doctor* next;
};

Doctor* head = NULL;

// a) Create list by appending a node
void appendDoctor()
{
    Doctor* newNode = new Doctor;

    cout << "\nEnter Doctor Name: ";
    cin >> newNode->name;

    cout << "Enter Specialization: ";
    cin >> newNode->specialization;

    cout << "Enter Phone Number: ";
    cin >> newNode->phone;

    newNode->prev = NULL;
    newNode->next = NULL;

    // If list is empty
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Doctor* temp = head;

        // Move to last node
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    cout << "\nDoctor added successfully!\n";
}

// b) List doctors for given specialization
void listBySpecialization()
{
    string spec;
    bool found = false;

    cout << "\nEnter Specialization: ";
    cin >> spec;

    Doctor* temp = head;

    cout << "\nDoctors with specialization " << spec << ":\n";

    while (temp != NULL)
    {
        if (temp->specialization == spec)
        {
            cout << "Doctor Name: " << temp->name << endl;
            cout << "Phone Number: " << temp->phone << endl;
            cout << "------------------------\n";

            found = true;
        }

        temp = temp->next;
    }

    if (!found)
    {
        cout << "No doctor found with this specialization.\n";
    }
}

// c) Reverse the doubly linked list
void reverseList()
{
    if (head == NULL)
    {
        cout << "\nList is empty!\n";
        return;
    }

    Doctor* current = head;
    Doctor* temp = NULL;

    // Swap prev and next for every node
    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        current = current->prev;
    }

    // Update head
    if (temp != NULL)
    {
        head = temp->prev;
    }

    cout << "\nList reversed successfully!\n";
}

// Display all doctors
void display()
{
    if (head == NULL)
    {
        cout << "\nList is empty!\n";
        return;
    }

    Doctor* temp = head;

    cout << "\n----- Doctor List -----\n";

    while (temp != NULL)
    {
        cout << "Doctor Name: " << temp->name << endl;
        cout << "Specialization: " << temp->specialization << endl;
        cout << "Phone Number: " << temp->phone << endl;
        cout << "------------------------\n";

        temp = temp->next;
    }
}

int main()
{
    int choice;

    // Menu displayed ONLY ONCE
    cout << "========== MENU ==========\n";
    cout << "1. Append a Doctor\n";
    cout << "2. List Doctors by Specialization\n";
    cout << "3. Reverse the List\n";
    cout << "4. Display All Doctors\n";
    cout << "5. Exit\n";
    cout << "==========================\n";

    do
    {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                appendDoctor();
                break;

            case 2:
                listBySpecialization();
                break;

            case 3:
                reverseList();
                break;

            case 4:
                display();
                break;

            case 5:
                cout << "\nProgram terminated.\n";
                break;

            default:
                cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}