#include <iostream>
using namespace std;

void display(float arr[], int n) {
    if (n == 0) {
        cout << "No data available.\n";
        return;
    }
    cout << "\nStudent Percentages:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Selection Sort with Pass & Iteration Display
void selectionSort(float arr[], int n) {
    cout << "\n--- Selection Sort ---\n";
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        cout << "Pass " << i + 1 << ":\n";
        for (int j = i + 1; j < n; j++) {
             cout << "   Iteration " << j << ": ";
            for (int k = 0; k < n; k++)
                cout << arr[k] << " ";
            cout << endl;

            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);

        cout << "After Pass " << i + 1 << ": ";
        for (int k = 0; k < n; k++)
            cout << arr[k] << " ";
        cout << endl;
    }
    cout << "Selection Sort Completed!\n";
}

// Bubble Sort with Pass & Iteration Display
void bubbleSort(float arr[], int n) {
    cout << "\n--- Bubble Sort ---\n";
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        cout << "Pass " << i + 1 << ":\n";
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
            cout << "   Iteration " << j + 1 << ": ";
            for (int k = 0; k < n; k++)
                cout << arr[k] << " ";
            cout << endl;
        }
        if (!swapped) break;
    }
    cout << "Bubble Sort Completed!\n";
}

// Display Top 5 Scores
void displayTopFive(float arr[], int n) {
    if (n == 0) {
        cout << "No data available.\n";
        return;
    }

    // Sort descending
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j])
                swap(arr[i], arr[j]);
        }
    }

    cout << "\nTop Five Scores:\n";
    for (int i = 0; i < 5 && i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    float marks[100];
    int n = 0, choice;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Add Student Percentages\n";
        cout << "2. Display List\n";
        cout << "3. Sort using Selection Sort\n";
        cout << "4. Sort using Bubble Sort\n";
        cout << "5. Display Top Five Scores\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter number of students: ";
            cin >> n;
            for (int i = 0; i < n; i++) {
                cout << "Enter percentage of student " << i + 1 << ": ";
                cin >> marks[i];
            }
            break;

        case 2:
            display(marks, n);
            break;

        case 3:
            selectionSort(marks, n);
            break;

        case 4:
            bubbleSort(marks, n);
            break;

        case 5:
            displayTopFive(marks, n);
            break;

        case 6:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 6);

    return 0;
}

