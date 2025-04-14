#include <iostream>
using namespace std;

int main() {
    int bucketSize, outputRate, n;

    cout << "Enter bucket size (in packets): ";
    cin >> bucketSize;

    cout << "Enter output rate (in packets/sec): ";
    cin >> outputRate;

    cout << "Enter number of incoming packets: ";
    cin >> n;

    int incoming[n];
    cout << "Enter size of each incoming packet:\n";
    for (int i = 0; i < n; i++) {
        cout << "Packet " << i + 1 << ": ";
        cin >> incoming[i];
    }

    int bucketContent = 0;

    cout << "\nTime\tIncoming\tBucket\tSent\tDropped\n";
    cout << "--------------------------------------------------\n";

    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t" << incoming[i] << "\t\t";

        // Add incoming to bucket
        if (incoming[i] + bucketContent <= bucketSize) {
            bucketContent += incoming[i];
        } else {
            int dropped = (incoming[i] + bucketContent) - bucketSize;
            bucketContent = bucketSize;
            cout << bucketContent << "\t" << outputRate << "\t" << dropped << "\n";
            bucketContent -= outputRate;
            if (bucketContent < 0) bucketContent = 0;
            continue;
        }

        // Leak packets (send out)
        int sent = (bucketContent >= outputRate) ? outputRate : bucketContent;
        bucketContent -= sent;

        cout << (bucketContent + sent) << "\t" << sent << "\t" << 0 << "\n";
    }

    // Process remaining packets in the bucket
    int time = n + 1;
    while (bucketContent > 0) {
        int sent = (bucketContent >= outputRate) ? outputRate : bucketContent;
        cout << time << "\t" << 0 << "\t\t" << bucketContent << "\t" << sent << "\t" << 0 << "\n";
        bucketContent -= sent;
        time++;
    }

    return 0;
}
