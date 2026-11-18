
#include <iostream>
using namespace std;

struct Node {
    int token;
    int priority;
    Node* next;

    Node(int t, int p) {
        token = t;
        priority = p;
        next = nullptr;
    }
};

class PriorityQueue {
    Node* front;

public:
    PriorityQueue() {
        front = nullptr;
    }

    // Insert a customer according to priority
    void insert(int token, int priority) {
        Node* temp = new Node(token, priority);

        // Insert at front if it has the highest priority
        if (front == nullptr || priority < front->priority) {
            temp->next = front;
            front = temp;
        } else {
            Node* current = front;

            // Insert after customers with equal priority
            while (current->next != nullptr &&
                   current->next->priority <= priority) {
                current = current->next;
            }

            temp->next = current->next;
            current->next = temp;
        }

        cout << "Token " << token
             << " added with priority " << priority << ".\n";
    }

    // Serve the highest-priority customer
    void serve() {
        if (front == nullptr) {
            cout << "Priority Queue is empty!\n";
            return;
        }

        Node* temp = front;

        cout << "Serving token " << temp->token
             << " (Priority " << temp->priority << ").\n";

        front = front->next;
        delete temp;
    }

    // Display all customers
    void display() {
        if (front == nullptr) {
            cout << "Priority Queue is empty!\n";
            return;
        }

        Node* current = front;

        cout << "\nToken\tPriority\n";
        cout << "----------------\n";

        while (current != nullptr) {
            cout << current->token << "\t"
                 << current->priority << endl;
            current = current->next;
        }
    }

    ~PriorityQueue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main() {
    PriorityQueue pq;
    int choice, token, priority;

    cout << "----- PRIORITY QUEUE -----\n";
    cout << "1. Insert customer\n";
    cout << "2. Serve customer\n";
    cout << "3. Display queue\n";
    cout << "4. Exit\n";

    do {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter token number: ";
            cin >> token;

            cout << "Enter priority (1 = highest): ";
            cin >> priority;

            pq.insert(token, priority);
            break;

        case 2:
            pq.serve();
            break;

        case 3:
            pq.display();
            break;

        case 4:
            cout << "Program terminated.\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
