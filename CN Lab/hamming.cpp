#include <iostream>
#include <vector>

using namespace std;

// Function to calculate parity bits
int calculate_parity(vector<int> &bits, vector<int> positions) {
    int parity = 0;
    for (int pos : positions) {
        parity ^= bits[pos - 1]; // Convert to 0-index
    }
    return parity;
}

// Function to encode 4-bit data into 7-bit Hamming code
vector<int> encode_hamming(vector<int> data) {
    vector<int> hamming(7, 0);
    hamming[2] = data[0]; // D3
    hamming[4] = data[1]; // D5
    hamming[5] = data[2]; // D6
    hamming[6] = data[3]; // D7

    // Set parity bits
    hamming[0] = calculate_parity(hamming, {1, 3, 5, 7}); // P1
    hamming[1] = calculate_parity(hamming, {2, 3, 6, 7}); // P2
    hamming[3] = calculate_parity(hamming, {4, 5, 6, 7}); // P4

    return hamming;
}

// Function to detect and correct a single-bit error
vector<int> detect_and_correct(vector<int> &received) {
    int p1 = calculate_parity(received, {1, 3, 5, 7});
    int p2 = calculate_parity(received, {2, 3, 6, 7});
    int p4 = calculate_parity(received, {4, 5, 6, 7});

    int error_pos = p4 * 4 + p2 * 2 + p1 * 1;

    if (error_pos != 0) {
        cout << "Error detected at position: " << error_pos << endl;
        received[error_pos - 1] ^= 1; // Flip the erroneous bit
    } else {
        cout << "No error detected." << endl;
    }

    return received;
}

int main() {
    vector<int> data(4);
    cout << "Enter 4 data bits (D3 D5 D6 D7): ";
    for (int i = 0; i < 4; i++) {
        cin >> data[i];
    }

    vector<int> hamming = encode_hamming(data);

    cout << "Encoded Hamming Code: ";
    for (int bit : hamming) {
        cout << bit << " ";
    }
    cout << endl;

    // Simulate error
    char simulate;
    cout << "Simulate error? (y/n): ";
    cin >> simulate;

    if (simulate == 'y' || simulate == 'Y') {
        int pos;
        cout << "Enter position to flip (1-7): ";
        cin >> pos;
        if (pos >= 1 && pos <= 7) {
            hamming[pos - 1] ^= 1;
        }
    }

    cout << "Received Code: ";
    for (int bit : hamming) {
        cout << bit << " ";
    }
    cout << endl;

    vector<int> corrected = detect_and_correct(hamming);

    cout << "Corrected Code: ";
    for (int bit : corrected) {
        cout << bit << " ";
    }
    cout << endl;

    return 0;
}
