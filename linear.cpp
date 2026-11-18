#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n;
    char students[100][50];
    char searchName[50];

    cout << "Enter number of students: ";
    cin >> n;

    cout << "Enter names of students:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> students[i];
    }

    cout << "\nEnter name to search: ";
    cin >> searchName;

    bool found = false;

    // Linear Search
    for (int i = 0; i < n; i++)
    {
        if (strcmp(students[i], searchName) == 0)
        {
            cout << "Name found at position " << i + 1 << endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Name not found." << endl;
    }

    return 0;
}