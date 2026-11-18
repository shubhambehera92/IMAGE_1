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

    // Sort names alphabetically
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strcmp(students[j], students[j + 1]) > 0)
            {
                char temp[50];

                strcpy(temp, students[j]);
                strcpy(students[j], students[j + 1]);
                strcpy(students[j + 1], temp);
            }
        }
    }

    cout << "\nNames in alphabetical order:\n";
    for (int i = 0; i < n; i++)
    {
        cout << students[i] << endl;
    }

    cout << "\nEnter name to search: ";
    cin >> searchName;

    // Binary Search
    int low = 0;
    int high = n - 1;
    bool found = false;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (strcmp(students[mid], searchName) == 0)
        {
            cout << "Name found at position " << mid + 1 << endl;
            found = true;
            break;
        }
        else if (strcmp(students[mid], searchName) < 0)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (!found)
    {
        cout << "Name not found." << endl;
    }

    return 0;
}