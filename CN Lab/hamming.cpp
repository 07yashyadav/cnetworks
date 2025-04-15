#include <iostream>
#include <cmath>
using namespace std;

// Function to calculate the number of redundant bits needed
int calcRedundantBits(int m) {
    for (int r = 0; r < m; r++) {
        if (pow(2, r) >= m + r + 1)
            return r;
    }
    return 0;
}

// Function to position redundant bits in the code
void insertParityBits(int data[], int m, int r, int hammingCode[]) {
    int j = 0, k = 0;

    for (int i = 1; i <= m + r; i++) {
        if (i == pow(2, j)) {
            hammingCode[i] = 0; // Placeholder for parity bit
            j++;
        } else {
            hammingCode[i] = data[k];
            k++;
        }
    }

    // Calculate parity bits
    for (int i = 0; i < r; i++) {
        int pos = pow(2, i);
        int parity = 0;

        for (int j = 1; j <= m + r; j++) {
            if (j & pos) {
                parity ^= hammingCode[j];
            }
        }

        hammingCode[pos] = parity;
    }
}

// Function to detect and correct single-bit error
int detectError(int hammingCode[], int totalBits, int r) {
    int errorPos = 0;

    for (int i = 0; i < r; i++) {
        int pos = pow(2, i);
        int parity = 0;

        for (int j = 1; j <= totalBits; j++) {
            if (j & pos) {
                parity ^= hammingCode[j];
            }
        }

        if (parity != 0) {
            errorPos += pos;
        }
    }

    return errorPos;
}

int main() {
    int m;
    cout << "Enter number of data bits: ";
    cin >> m;

    int data[m];
    cout << "Enter data bits (MSB to LSB): ";
    for (int i = 0; i < m; i++) {
        cin >> data[i];
    }

    int r = calcRedundantBits(m);
    int totalBits = m + r;
    int hammingCode[totalBits + 1]; // 1-based indexing

    insertParityBits(data, m, r, hammingCode);

    cout << "\nHamming code generated: ";
    for (int i = totalBits; i >= 1; i--) {
        cout << hammingCode[i] << " ";
    }
    cout << endl;

    // Introduce an error
    char inject;
    cout << "\nDo you want to introduce an error? (y/n): ";
    cin >> inject;

    if (inject == 'y' || inject == 'Y') {
        int errorBit;
        cout << "Enter bit position to flip (1 to " << totalBits << "): ";
        cin >> errorBit;
        if (errorBit >= 1 && errorBit <= totalBits) {
            hammingCode[errorBit] ^= 1; // Flip the bit

            cout << "Corrupted Hamming code: ";
            for (int i = totalBits; i >= 1; i--) {
                cout << hammingCode[i] << " ";
            }
            cout << endl;
        }
    }

    int errorPos = detectError(hammingCode, totalBits, r);

    if (errorPos == 0) {
        cout << "No error detected in the Hamming code.\n";
    } else {
        cout << "Error detected at position: " << errorPos << endl;
        cout << "Correcting the error...\n";
        hammingCode[errorPos] ^= 1;

        cout << "Corrected Hamming code: ";
        for (int i = totalBits; i >= 1; i--) {
            cout << hammingCode[i] << " ";
        }
        cout << endl;
    }

    return 0;
}


// Enter number of data bits: 4
// Enter data bits (MSB to LSB): 1 0 1 1

// Hamming code generated: 1 1 0 0 1 1 0

// Do you want to introduce an error? (y/n): y
// Enter bit position to flip (1 to 7): 3
// Corrupted Hamming code: 1 1 0 0 0 1 0
// Error detected at position: 3
// Correcting the error...
// Corrected Hamming code: 1 1 0 0 1 1 0
