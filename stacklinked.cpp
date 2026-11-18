
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Stack using linked representation
class Stack {
    struct Node {
        int data;
        Node* next;

        Node(int value) {
            data = value;
            next = nullptr;
        }
    };

    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(int value) {
        Node* temp = new Node(value);
        temp->next = top;
        top = temp;
    }

    int pop() {
        if (top == nullptr) {
            cout << "Stack Underflow!\n";
            return 0;
        }

        Node* temp = top;
        int value = temp->data;
        top = top->next;
        delete temp;
        return value;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    ~Stack() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

// Perform arithmetic operation
int calculate(int a, int b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;

    case '/':
        if (b == 0) {
            throw "Division by zero!";
        }
        return a / b;

    case '%':
        if (b == 0) {
            throw "Modulo by zero!";
        }
        return a % b;
    }

    throw "Invalid operator!";
}

// Evaluate postfix expression
int evaluatePostfix(string exp) {
    Stack s;

    for (int i = 0; i < (int)exp.length(); i++) {
        char ch = exp[i];

        if (isspace(ch))
            continue;

        if (isdigit(ch)) {
            s.push(ch - '0');
        }
        else {
            int b = s.pop();
            int a = s.pop();
            s.push(calculate(a, b, ch));
        }
    }

    return s.pop();
}

// Evaluate prefix expression
int evaluatePrefix(string exp) {
    Stack s;

    for (int i = (int)exp.length() - 1; i >= 0; i--) {
        char ch = exp[i];

        if (isspace(ch))
            continue;

        if (isdigit(ch)) {
            s.push(ch - '0');
        }
        else {
            int a = s.pop();
            int b = s.pop();
            s.push(calculate(a, b, ch));
        }
    }

    return s.pop();
}

int main() {
    int choice;
    string exp;

    // Display menu only once
    cout << "----- STACK OPERATIONS -----\n";
    cout << "1. Evaluate Postfix Expression\n";
    cout << "2. Evaluate Prefix Expression\n";
    cout << "3. Exit\n";

    do {
        cout << "\nEnter your choice: ";
        cin >> choice;

        try {
            switch (choice) {
            case 1:
                cout << "Enter valid postfix expression: ";
                cin >> exp;

                cout << "Result = "
                     << evaluatePostfix(exp) << endl;
                break;

            case 2:
                cout << "Enter valid prefix expression: ";
                cin >> exp;

                cout << "Result = "
                     << evaluatePrefix(exp) << endl;
                break;

            case 3:
                cout << "Program terminated.\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
            }
        }
        catch (const char* message) {
            cout << "Error: " << message << endl;
        }

    } while (choice != 3);

    return 0;
}
