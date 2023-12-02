#include <iostream>
#include <sstream>
#include <algorithm>
#include "hashmap.h"
using namespace std;

int main() {

    HashMap<string, int> mapping;
    string text;
    cout << "Please input any text you would like : ";
    getline(cin, text);
    replace(text.begin(), text.end(), '.', ' ');
    istringstream separate(text);
    string word;
    while (separate >> word) {
        mapping.put(word);
    }
    mapping.display();

    return 0;
}
