#include<iostream>
using namespace std;

int main() {
    int op;
    cout << "Enter number of operations: ";
    cin >> op;

    string operation[100];
    int X = 0;

    cout << "Enter " << op << " operations (e.g., ++X, X++, --X, X--):\n";
    for (int i = 0; i < op; i++) {
        cin >> operation[i];   
    }
    

    for (int i = 0; i < op; i++) {
        if (operation[i]=="++X" || operation[i]=="X++") {
            X++;
        } else if (operation[i]=="--X" || operation[i]=="X--") {
            X--;
        }
    }

    cout << "Final value of X: " << X;
    return 0;
}

