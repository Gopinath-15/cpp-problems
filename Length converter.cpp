#include <iostream>
using namespace std;

int main() {
    int choice;
    double value, result;

    cout << "Kilometers and Miles Converter\n";
    cout << "1. Kilometers to Miles\n";
    cout << "2. Miles to Kilometers\n";
    cout << "Enter your choice (1-2): ";
    cin >> choice;

    if (choice < 1 || choice > 2) {
        cout << "Invalid choice!" << endl;
        return 0;
    }

    cout << "Enter the value to convert: ";
    cin >> value;

    if (choice == 1) { 
        result = value * 0.621371;
        cout << value << " km = " << result << " miles" << endl;
    } else { 
        result = value * 1.60934;
        cout << value << " miles = " << result << " km" << endl;
    }

    return 0;
}
