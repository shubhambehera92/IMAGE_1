
#include <iostream>
using namespace std;

struct Node {
    int coeff, expX, expY;
    Node* next;

    Node(int c = 0, int x = 0, int y = 0) {
        coeff = c;
        expX = x;
        expY = y;
        next = nullptr;
    }
};

class Polynomial {
    Node* head;

public:
    Polynomial() {
        head = new Node();
        head->next = head;   // Circular linked list
    }

    void insertTerm(int c, int x, int y) {
        if (c == 0) return;

        Node* prev = head;
        Node* curr = head->next;

        // Combine terms having the same exponents
        while (curr != head) {
            if (curr->expX == x && curr->expY == y) {
                curr->coeff += c;

                if (curr->coeff == 0) {
                    prev->next = curr->next;
                    delete curr;
                }
                return;
            }
            prev = curr;
            curr = curr->next;
        }

        Node* temp = new Node(c, x, y);
        temp->next = head;
        prev->next = temp;
    }

    void create() {
        int n, c, x, y;

        // Clear the previous polynomial
        Node* curr = head->next;
        while (curr != head) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
        head->next = head;

        cout << "Enter number of terms: ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            cout << "Enter coefficient, exponent of x and exponent of y: ";
            cin >> c >> x >> y;
            insertTerm(c, x, y);
        }
    }

    void display() const {
        Node* curr = head->next;

        if (curr == head) {
            cout << "0";
            return;
        }

        bool first = true;

        while (curr != head) {
            int c = curr->coeff;

            if (!first) {
                cout << (c > 0 ? " + " : " - ");
            } else if (c < 0) {
                cout << "-";
            }

            int absC = (c < 0) ? -c : c;

            if (absC != 1 ||
                (curr->expX == 0 && curr->expY == 0)) {
                cout << absC;
            }

            if (curr->expX > 0) {
                cout << "x";
                if (curr->expX > 1)
                    cout << "^" << curr->expX;
            }

            if (curr->expY > 0) {
                cout << "y";
                if (curr->expY > 1)
                    cout << "^" << curr->expY;
            }

            first = false;
            curr = curr->next;
        }
    }

    Polynomial add(const Polynomial& other) const {
        Polynomial result;

        Node* curr = head->next;
        while (curr != head) {
            result.insertTerm(curr->coeff, curr->expX, curr->expY);
            curr = curr->next;
        }

        curr = other.head->next;
        while (curr != other.head) {
            result.insertTerm(curr->coeff, curr->expX, curr->expY);
            curr = curr->next;
        }

        return result;
    }

    double evaluate(double x, double y) const {
        double sum = 0;
        Node* curr = head->next;

        while (curr != head) {
            double term = curr->coeff;

            for (int i = 0; i < curr->expX; i++)
                term *= x;

            for (int i = 0; i < curr->expY; i++)
                term *= y;

            sum += term;
            curr = curr->next;
        }

        return sum;
    }
};


int main() {
    Polynomial P, Q, R;
    int choice, polyChoice;
    double x, y;

    // Display menu only once
    cout << "\n--- POLYNOMIAL MENU ---\n";
    cout << "1. Create polynomial\n";
    cout << "2. Display polynomial\n";
    cout << "3. Add two polynomials\n";
    cout << "4. Evaluate polynomial\n";
    cout << "5. Exit\n";

    do {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Create Polynomial P:\n";
            P.create();

            cout << "Create Polynomial Q:\n";
            Q.create();
            break;

        case 2:
            cout << "Polynomial P = ";
            P.display();

            cout << "\nPolynomial Q = ";
            Q.display();
            cout << endl;
            break;

        case 3:
            R = P.add(Q);
            cout << "P + Q = ";
            R.display();
            cout << endl;
            break;

        case 4:
            cout << "Evaluate which polynomial? (1=P, 2=Q): ";
            cin >> polyChoice;

            cout << "Enter values of x and y: ";
            cin >> x >> y;

            if (polyChoice == 1)
                cout << "Value of P = " << P.evaluate(x, y);
            else if (polyChoice == 2)
                cout << "Value of Q = " << Q.evaluate(x, y);
            else
                cout << "Invalid polynomial choice!";

            cout << endl;
            break;

        case 5:
            cout << "Program terminated.\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
