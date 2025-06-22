#include <iostream>
using namespace std;

int main() {
    int choice;
    double value, result;

    cout << "Temperature Converter\n";
    cout << "1. Celsius to Fahrenheit\n";
    cout << "2. Fahrenheit to Celsius\n";
    cout << "Enter your choice (1-2): ";
    cin >> choice;

    if (choice < 1 || choice > 2) {
        cout << "Invalid choice!" << endl;
        return 0;
    }

    cout << "Enter the temperature to convert: ";
    cin >> value;

    if (choice == 1) { // Celsius to Fahrenheit
        result = (value * 9.0 / 5.0) + 32;
        cout << value << " °C = " << result << " °F" << endl;
    } else { // Fahrenheit to Celsius
        result = (value - 32) * 5.0 / 9.0;
        cout << value << " °F = " << result << " °C" << endl;
    }

    return 0;
}
