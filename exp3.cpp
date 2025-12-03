#include <iostream>
using namespace std;

// Function for Linear Search
int linearSearch(int arr[], int n, int key, int &comparisons) {
    comparisons = 0;
    for (int i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == key)
            return i; // found
    }
    return -1;
}

// Function for Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout << "Array has been sorted using Bubble Sort.\n";
}

// Function for Binary Search
int binarySearch(int arr[], int n, int key, int &comparisons) {
    int low = 0, high = n - 1;
    comparisons = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        comparisons++;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int roll[100];
    int n = 0, choice, key, pos;
    int linComp, binComp;
    bool sorted = false;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Add Student Roll Numbers\n";
        cout << "2. Display List\n";
        cout << "3. Perform Linear Search\n";
        cout << "4. Perform Bubble Sort\n";
        cout << "5. Perform Binary Search\n";
        cout << "6. Compare Both Algorithms\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter number of students: ";
                cin >> n;
                cout << "Enter roll numbers: ";
                for (int i = 0; i < n; i++) {
                    cin >> roll[i];
                }
                sorted = false;
                cout << "Roll numbers added successfully!\n";
                break;
            }

            case 2: {
                if (n == 0) {
                    cout << "No data available.\n";
                } else {
                    cout << "Student Roll Numbers: ";
                    for (int i = 0; i < n; i++)
                        cout << roll[i] << " ";
                    cout << endl;
                }
                break;
            }

            case 3: {
                if (n == 0) {
                    cout << "No students added yet!\n";
                    break;
                }
                cout << "Enter roll number to search (Linear Search): ";
                cin >> key;
                pos = linearSearch(roll, n, key, linComp);
                if (pos != -1)
                    cout << "Student found at position " << pos + 1 << endl;
                else
                    cout << "Student not found.\n";
                cout << "Comparisons made: " << linComp << endl;
                break;
            }

            case 4: {
                if (n == 0) {
                    cout << "No students added yet!\n";
                    break;
                }
                bubbleSort(roll, n);
                sorted = true;
                break;
            }

            case 5: {
                if (n == 0) {
                    cout << "No students added yet!\n";
                    break;
                }
                if (!sorted) {
                    cout << "Array not sorted! Please perform Bubble Sort first.\n";
                    break;
                }
                cout << "Enter roll number to search (Binary Search): ";
                cin >> key;
                pos = binarySearch(roll, n, key, binComp);
                if (pos != -1)
                    cout << "Student found at position " << pos + 1 << endl;
                else
                    cout << "Student not found.\n";
                cout << "Comparisons made: " << binComp << endl;
                break;
            }

            case 6: {
                if (n == 0) {
                    cout << "No students added yet!\n";
                    break;
                }
                cout << "Enter roll number to search: ";
                cin >> key;

                // Perform Linear Search
                int linPos = linearSearch(roll, n, key, linComp);

                // Sort copy for Binary Search
                int sortedArr[100];
                for (int i = 0; i < n; i++)
                    sortedArr[i] = roll[i];
                bubbleSort(sortedArr, n);

                int binPos = binarySearch(sortedArr, n, key, binComp);

                cout << "\n--- COMPARISON ---\n";
                if (linPos != -1)
                    cout << "Linear Search: Found (Comparisons = " << linComp << ")\n";
                else
                    cout << "Linear Search: Not Found (Comparisons = " << linComp << ")\n";

                if (binPos != -1)
                    cout << "Binary Search: Found (Comparisons = " << binComp << ")\n";
                else
                    cout << "Binary Search: Not Found (Comparisons = " << binComp << ")\n";

                if (binComp < linComp)
                    cout << "\nBinary Search is more efficient (" << binComp << " < " << linComp << " comparisons)\n";
                else if (binComp > linComp)
                    cout << "\n Linear Search took fewer comparisons (" << linComp << " < " << binComp << ")\n";
                else
                    cout << "\n Both searches took the same number of comparisons.\n";
                break;
            }

            case 7:
                cout << "Exiting program... Goodbye!\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 7);

    return 0;
}
