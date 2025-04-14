#include <iostream>
using namespace std;

int main() {
    int bucketSize, tokenRate, n;

    cout << "Enter bucket size (in tokens): ";
    cin >> bucketSize;

    cout << "Enter token generation rate (tokens/sec): ";
    cin >> tokenRate;

    cout << "Enter number of incoming packets: ";
    cin >> n;

    int packets[n];
    cout << "Enter size of each incoming packet:\n";
    for (int i = 0; i < n; i++) {
        cout << "Packet " << i + 1 << ": ";
        cin >> packets[i];
    }

    int tokens = 0;

    cout << "\nTime\tPacket Size\tTokens\tStatus\n";
    cout << "-----------------------------------------\n";

    for (int i = 0; i < n; i++) {
        // Generate tokens
        tokens += tokenRate;
        if (tokens > bucketSize) {
            tokens = bucketSize;
        }

        cout << i + 1 << "\t" << packets[i] << "\t\t" << tokens << "\t";

        if (packets[i] <= tokens) {
            // Send packet
            tokens -= packets[i];
            cout << "Sent\n";
        } else {
            // Drop packet
            cout << "Dropped\n";
        }
    }

    return 0;
}
