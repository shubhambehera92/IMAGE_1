
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <limits>
using namespace std;

const int MAX = 100;

// Structure for ticket details
struct Ticket {
    int id;
    string customer;
    string issue;
    int priority;
    string status;
};

// Node for linked list
struct Node {
    Ticket data;
    Node* next;
};

Ticket tickets[MAX];
int ticketCount = 0;

queue<int> waitingQueue;
stack<int> resolvedStack;
Node* resolvedHead = NULL;

// Add resolved ticket to linked list
void addToResolvedList(Ticket t) {
    Node* newNode = new Node;
    newNode->data = t;
    newNode->next = NULL;

    if (resolvedHead == NULL) {
        resolvedHead = newNode;
    } else {
        Node* temp = resolvedHead;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }
}

// 1. Create a new ticket
void createTicket() {
    if (ticketCount >= MAX) {
        cout << "Ticket storage is full!\n";
        return;
    }

    Ticket t;
    t.id = 1001 + ticketCount;

    cout << "Enter customer name: ";
    getline(cin, t.customer);

    cout << "Enter issue: ";
    getline(cin, t.issue);

    cout << "Enter priority (1=High, 2=Medium, 3=Low): ";

    if (!(cin >> t.priority)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid priority input.\n";
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (t.priority < 1 || t.priority > 3) {
        cout << "Invalid priority. Use 1, 2, or 3.\n";
        return;
    }

    t.status = "Waiting";
    tickets[ticketCount] = t;

    waitingQueue.push(ticketCount);
    ticketCount++;

    cout << "\nTicket created successfully!\n";
    cout << "Ticket ID: " << t.id << "\n";
}

// 2. Display all tickets
void displayAllTickets() {
    if (ticketCount == 0) {
        cout << "No tickets available.\n";
        return;
    }

    cout << "\n--- ALL TICKETS ---\n";

    for (int i = 0; i < ticketCount; i++) {
        cout << "ID: " << tickets[i].id
             << " | Customer: " << tickets[i].customer
             << " | Issue: " << tickets[i].issue
             << " | Priority: " << tickets[i].priority
             << " | Status: " << tickets[i].status << "\n";
    }
}

// 3. Resolve next ticket using queue
void resolveNextTicket() {
    if (waitingQueue.empty()) {
        cout << "No customers are waiting.\n";
        return;
    }

    int index = waitingQueue.front();
    waitingQueue.pop();

    tickets[index].status = "Resolved";

    resolvedStack.push(index);
    addToResolvedList(tickets[index]);

    cout << "\nTicket resolved successfully!\n";
    cout << "Ticket ID: " << tickets[index].id << "\n";
    cout << "Customer: " << tickets[index].customer << "\n";
}

// 4. Display waiting queue
void displayWaitingQueue() {
    if (waitingQueue.empty()) {
        cout << "Waiting queue is empty.\n";
        return;
    }

    queue<int> temp = waitingQueue;

    cout << "\n--- WAITING QUEUE (FIFO) ---\n";

    while (!temp.empty()) {
        int index = temp.front();
        temp.pop();

        cout << "Ticket ID: " << tickets[index].id
             << " | Customer: " << tickets[index].customer
             << " | Priority: " << tickets[index].priority << "\n";
    }
}

// 5. Search ticket using linear search
void searchTicket() {
    int id;

    cout << "Enter ticket ID to search: ";

    if (!(cin >> id)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid ticket ID.\n";
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < ticketCount; i++) {
        if (tickets[i].id == id) {
            cout << "\nTicket Found!\n";
            cout << "Ticket ID: " << tickets[i].id << "\n";
            cout << "Customer: " << tickets[i].customer << "\n";
            cout << "Issue: " << tickets[i].issue << "\n";
            cout << "Priority: " << tickets[i].priority << "\n";
            cout << "Status: " << tickets[i].status << "\n";
            return;
        }
    }

    cout << "Ticket not found.\n";
}

// 6. Sort tickets using bubble sort
void sortTickets() {
    if (ticketCount == 0) {
        cout << "No tickets to sort.\n";
        return;
    }

    Ticket sorted[MAX];

    for (int i = 0; i < ticketCount; i++)
        sorted[i] = tickets[i];

    for (int i = 0; i < ticketCount - 1; i++) {
        for (int j = 0; j < ticketCount - i - 1; j++) {
            if (sorted[j].priority > sorted[j + 1].priority) {
                Ticket temp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = temp;
            }
        }
    }

    cout << "\n--- TICKETS SORTED BY PRIORITY ---\n";

    for (int i = 0; i < ticketCount; i++) {
        cout << "ID: " << sorted[i].id
             << " | Customer: " << sorted[i].customer
             << " | Priority: " << sorted[i].priority
             << " | Status: " << sorted[i].status << "\n";
    }
}

// 7. Display resolved tickets using linked list
void displayResolvedList() {
    if (resolvedHead == NULL) {
        cout << "No resolved tickets available.\n";
        return;
    }

    cout << "\n--- RESOLVED TICKETS (LINKED LIST) ---\n";

    Node* temp = resolvedHead;

    while (temp != NULL) {
        cout << "ID: " << temp->data.id
             << " | Customer: " << temp->data.customer
             << " | Issue: " << temp->data.issue << "\n";

        temp = temp->next;
    }
}

// 8. Display resolved tickets using stack
void displayResolvedStack() {
    if (resolvedStack.empty()) {
        cout << "Resolved ticket stack is empty.\n";
        return;
    }

    stack<int> temp = resolvedStack;

    cout << "\n--- RESOLVED TICKET STACK (LIFO) ---\n";

    while (!temp.empty()) {
        int index = temp.top();
        temp.pop();

        cout << "Ticket ID: " << tickets[index].id
             << " | Customer: " << tickets[index].customer << "\n";
    }
}

// Free linked-list memory
void cleanup() {
    while (resolvedHead != NULL) {
        Node* temp = resolvedHead;
        resolvedHead = resolvedHead->next;
        delete temp;
    }
}

int main() {
    int choice;

    // Display menu only once
    cout << "====================================\n";
    cout << " CALL CENTER TICKET HANDLING SYSTEM\n";
    cout << "====================================\n";
    cout << "1. Create New Ticket\n";
    cout << "2. Display All Tickets\n";
    cout << "3. Resolve Next Ticket\n";
    cout << "4. Display Waiting Queue\n";
    cout << "5. Search Ticket by ID\n";
    cout << "6. Sort Tickets by Priority\n";
    cout << "7. Display Resolved Tickets (Linked List)\n";
    cout << "8. Display Resolved Ticket Stack\n";
    cout << "0. Exit\n";

    do {
        cout << "\nEnter your choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Enter a number.\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                createTicket();
                break;

            case 2:
                displayAllTickets();
                break;

            case 3:
                resolveNextTicket();
                break;

            case 4:
                displayWaitingQueue();
                break;

            case 5:
                searchTicket();
                break;

            case 6:
                sortTickets();
                break;

            case 7:
                displayResolvedList();
                break;

            case 8:
                displayResolvedStack();
                break;

            case 0:
                cout << "Thank you for using the system!\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);

    cleanup();
    return 0;
}
