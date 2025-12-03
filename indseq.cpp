#include<iostream>
using namespace std;

int indxseq(int arr[], int size, int num) {
    int valarr[size], indxarr[size], indx = 0;
    int found = 0, maybe = 0, start = 0, end = size;

    // store every 3rd element as checkpoint
    for (int i = 0; i < size; i += 3) {
        valarr[indx] = arr[i];
        indxarr[indx] = i;
        indx++;
    }

    // quick rejection if smaller than first checkpoint
    if (num < valarr[0])
        return 0;

    // determine search range
    for (int i = 1; i < indx; i++) {
        if (num <= valarr[i]) {
            start = indxarr[i-1];
            end = indxarr[i];
            maybe = 1;
            break;
        }
    }

    if (maybe == 0) { // number may be after last checkpoint
        start = indxarr[indx-1];
        end = size;
    }

    // sequential search in that block
    for (int i = start; i < end; i++) {
        if (arr[i] == num) {
            found = 1;
            break;
        }
    }

    return found;
}

int main() {
    const int size = 12;
    int arr[size] = {10,20,30,40,50,60,70,80,90,100,110,120};
    int num;

    cout << "Enter the number to be searched: ";
    cin >> num;

    int rv = indxseq(arr, size, num);

    if (rv == 1)
        cout << "\nNumber Found!!";
    else
        cout << "\nNumber Not Found!!";

    return 0;
}