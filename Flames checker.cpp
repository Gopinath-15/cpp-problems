#include <iostream>
#include <string>
using namespace std;

string calculateFLAMES(string name1, string name2) {
    // Count letters using frequency array (ASCII range)
    int freq[128] = {0};
    for (char c : name1) freq[c]++;
    for (char c : name2) freq[c]--;


    int total = 0;
    for (int i = 0; i < 128; i++) total += abs(freq[i]);

    if (total == 0) return "Invalid";


    string flames = "FLAMES";
    int index = 0;
    while (flames.length() > 1) {
        index = (index + total - 1) % flames.length();
        flames.erase(index, 1);
    }


    switch (flames[0]) {
        case 'F': return "Friends";
        case 'L': return "Lovers";
        case 'A': return "Affection";
        case 'M': return "Marriage";
        case 'E': return "Enemies";
        case 'S': return "Siblings";
        default: return "Invalid";
    }
}

int main() {
    string name1, name2;
    cout << "First name: ";
    getline(cin, name1);
    cout << "Second name: ";
    getline(cin, name2);
    cout << "Relationship: " << calculateFLAMES(name1, name2) << endl;
    return 0;
}
