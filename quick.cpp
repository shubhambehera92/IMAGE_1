#include<iostream>
using namespace std;

// Partition function
int partition(int arr[], int st, int end) {
    int pivot = arr[end];
    int i = st - 1;

    for(int j = st; j < end; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[end]);
    return i + 1;
}

// Quick Sort function
void quickSort(int arr[], int st, int end) {
    if(st < end) {
        int pivotIndex = partition(arr, st, end);

        quickSort(arr, st, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, end);
    }
}

// Display array
void display(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int main() {
    int *arr = NULL;
    int n, choice;

    do {
        cout << "\n------MENU------\n";
        cout << "1. Create Dynamic Array\n";
        cout << "2. Display Array\n";
        cout << "3. Quick Sort\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
                if(arr != NULL) {
                    delete[] arr;
                }

                cout << "Enter number of elements: ";
                cin >> n;

                arr = new int[n];

                cout << "Enter " << n << " Numbers\n";
                for(int i = 0; i < n; i++) {
                    cin >> arr[i];
                }
                break;

            case 2:
                if(arr == NULL) {
                    cout << "Array not created\n";
                }
                else {
                    display(arr, n);
                }
                break;

            case 3:
                if(arr == NULL) {
                    cout << "Array not created\n";
                }
                else {
                    quickSort(arr, 0, n - 1);
                    cout << "Array sorted successfully\n";
                    display(arr, n);
                }
                break;

            case 4:
                cout << "Exiting.......\n";
                break;

            default:
                cout << "Invalid Choice\n";
        }

    } while(choice != 4);

    delete[] arr;

    return 0;
}