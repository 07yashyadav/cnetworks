#include <iostream>
using namespace std;

// XOR operation ka function (binary division ke liye)
string xorOperation(string dividend, string divisor) {
    int n = divisor.length();
    for (int i = 0; i <= dividend.length() - n; ) {
        for (int j = 0; j < n; j++)
            dividend[i + j] = (dividend[i + j] == divisor[j]) ? '0' : '1';
        
        // Next 1 bit dhundo
        while (i < dividend.length() && dividend[i] != '1') 
            i++;
    }
    return dividend.substr(dividend.length() - n + 1); // Remainder return karo
}

// Sender Side: Data bits me CRC add karna
string encodeData(string data, string divisor) {
    int m = divisor.length();
    string paddedData = data + string(m - 1, '0'); // Data ke end me divisor ke size -1 ke barabar 0 add karo
    string remainder = xorOperation(paddedData, divisor);
    return data + remainder; // Transmitted data (Data + Remainder)
}
// Receiver Side: Error detection
bool checkData(string receivedData, string divisor) {
    string remainder = xorOperation(receivedData, divisor);
    return remainder.find('1') == string::npos; // Agar remainder 0 hai to error nahi hai
}

int main() {
    string data, divisor;
    
    cout << "Enter Data Bits: ";
    cin >> data;
    cout << "Enter Divisor (Generator Polynomial): ";
    cin >> divisor;

    // Encode the data
    string transmittedData = encodeData(data, divisor);
    cout << "Transmitted Data (Data + CRC): " << transmittedData << endl;

    // Simulating Transmission (Receiver Side)
    cout << "Enter Received Data: ";
    string receivedData;
    cin >> receivedData;

    if (checkData(receivedData, divisor))
        cout << "No Error Detected. Data is Correct!" << endl;
    else
        cout << "Error Detected in Received Data!" << endl;

    return 0;
}