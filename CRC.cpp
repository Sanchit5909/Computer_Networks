#include <iostream>
#include <sstream>
using namespace std;

int main() {
    string ip;
    int first;

    cout << "Enter IP address: ";
    cin >> ip;

    stringstream ss(ip);
    string temp;

    getline(ss, temp, '.');
    first = stoi(temp);

    cout << "Given IP Address: " << ip << endl;

    if (first >= 1 && first <= 127)
        cout << "Class: A";
    else if (first >= 128 && first <= 191)
        cout << "Class: B";
    else if (first >= 192 && first <= 223)
        cout << "Class: C";
    else if (first >= 224 && first <= 239)
        cout << "Class: D";
    else if (first >= 240 && first <= 255)
        cout << "Class: E";
    else
        cout << "Invalid IP Address";

    return 0;
}