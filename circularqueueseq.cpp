
#include <iostream>
using namespace std;

#define MAX 50

class CircularQueue {
    int q[MAX];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // Issue a token (Insert)
    void insert(int token) {
        if ((rear + 1) % MAX == front) {
            cout << "Queue Overflow! Queue is full.\n";
            return;
        }

        if (front == -1) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX;
        }

        q[rear] = token;
        cout << "Token number " << token
             << " issued successfully.\n";
    }

    // Serve a customer (Delete)
    void serve() {
        if (front == -1) {
            cout << "Queue Underflow! No customers to serve.\n";
            return;
        }

        cout << "Customer with token number "
             << q[front] << " has been served.\n";

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }

    // Display waiting tokens
    void display() {
        if (front == -1) {
            cout << "No customers waiting in the queue.\n";
            return;
        }

        cout << "Waiting customer token numbers: ";

        int i = front;
        while (true) {
            cout << q[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % MAX;
        }

        cout << endl;
    }
};

int main() {
    CircularQueue q;
    int choice;
    int token = 1;

    // Display menu only once
    cout << "----- CIRCULAR QUEUE OPERATIONS -----\n";
    cout << "1. Issue a token\n";
    cout << "2. Serve a customer\n";
    cout << "3. Display waiting tokens\n";
    cout << "4. Exit\n";

    do {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            q.insert(token++);
            break;

        case 2:
            q.serve();
            break;

        case 3:
            q.display();
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
