
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

#define MAX 100

// Stack using sequential (array) representation
class Stack {
    char arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(char ch) {
        if (top == MAX - 1)
            cout << "Stack Overflow!\n";
        else
            arr[++top] = ch;
    }

    char pop() {
        if (isEmpty())
            return '\0';
        return arr[top--];
    }

    char peek() {
        if (isEmpty())
            return '\0';
        return arr[top];
    }
};

int precedence(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/' || op == '%')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

// Convert infix expression to postfix
string infixToPostfix(string infix) {
    Stack s;
    string postfix = "";

    for (int i = 0; i < (int)infix.length(); i++) {
        char ch = infix[i];

        if (isspace(ch))
            continue;

        if (isalnum(ch)) {
            postfix += ch;
        }
        else if (ch == '(') {
            s.push(ch);
        }
        else if (ch == ')') {
            while (!s.isEmpty() && s.peek() != '(')
                postfix += s.pop();

            if (!s.isEmpty())
                s.pop();
        }
        else {
            while (!s.isEmpty() && s.peek() != '(' &&
                  (precedence(s.peek()) > precedence(ch) ||
                  (precedence(s.peek()) == precedence(ch) &&
                   ch != '^'))) {
                postfix += s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.isEmpty())
        postfix += s.pop();

    return postfix;
}

// Convert postfix expression to prefix
string postfixToPrefix(string postfix) {
    string s[MAX];
    int top = -1;

    for (int i = 0; i < (int)postfix.length(); i++) {
        char ch = postfix[i];

        if (isspace(ch))
            continue;

        if (isalnum(ch)) {
            s[++top] = string(1, ch);
        }
        else {
            string b = s[top--];
            string a = s[top--];

            s[++top] = string(1, ch) + a + b;
        }
    }

    return s[top];
}

int main() {
    int choice;
    string infix, postfix;

    // Display menu only once
    cout << "----- STACK OPERATIONS -----\n";
    cout << "1. Infix to Postfix\n";
    cout << "2. Infix to Prefix\n";
    cout << "3. Exit\n";

    do {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter valid infix expression: ";
            cin >> infix;

            postfix = infixToPostfix(infix);
            cout << "Postfix expression: " << postfix << endl;
            break;

        case 2:
            cout << "Enter valid infix expression: ";
            cin >> infix;

            postfix = infixToPostfix(infix);
            cout << "Prefix expression: "
                 << postfixToPrefix(postfix) << endl;
            break;

        case 3:
            cout << "Program terminated.\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 3);

    return 0;
}
