#include <iostream>
#include <unordered_map>
#include <cctype>

using namespace std;

int main() {
    string paragraph;
    unordered_map<char, int> frequency;

    cout << "Enter a paragraph: ";
    getline(cin, paragraph);

    for (char c : paragraph) {
        if (isalpha(c)) {
            c = tolower(c);
            frequency[c]++;
        }
    }

    cout << "Character frequencies:\n";
    for (auto& pair : frequency) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}

