#include <iostream>
#include <string>
using namespace std;

int countBeams(int devices[], int size, int index) {
    if (index >= size - 1)
        return 0;

    return devices[index] * devices[index + 1] + countBeams(devices, size, index + 1);
}

int main() {
    string bank[] = {"011001", "000000", "010100", "001000"};
    int n = sizeof(bank) / sizeof(bank[0]);

    int devices[100]; 
    int countIndex = 0;

   
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (char c : bank[i]) {
            if (c == '1')
                count++;
        }
        if (count > 0)
            devices[countIndex++] = count;
    }

    int totalBeams = countBeams(devices, countIndex, 0);

    cout << "Total laser beams: " << totalBeams << endl;

    return 0;
}
