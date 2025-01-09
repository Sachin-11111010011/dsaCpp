#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    
    string words[] = {"pay", "attention", "practice", "attend","atlas"};
    string pref = "at";

    
    int size = sizeof(words) / sizeof(string);
    cout << "Size of array: " << size << endl;

    // Example loop to count words starting with 'pref'
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (words[i].rfind(pref, 0) == 0) { // Check if the word starts with 'pref'
            count++;
        }
    }

    cout << "Number of words starting with '" << pref << "': " << count << endl;

    return 0;
}
