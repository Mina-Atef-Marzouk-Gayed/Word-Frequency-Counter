#include <iostream>
#include <sstream>
#include "hashmap.h"
using namespace std;

void replaceNonCharactersWithSpace(string& text) {
    for (char& c : text) {
        if (!isalpha(c)) {
            c = ' ';
        }
    }
}
void splitText(string& text)
{
    HashMap<string, int> mapping;
    istringstream separate(text);
    string word;
    while (separate >> word) {
        mapping.put(word);
    }
    mapping.display();
    cout << "\n\ntest copy constructor and sorting" << endl;
    HashMap<string, int> map2(mapping);
    map2.display();

}

int main() {

   
    string text;
    cout << "Please input any text you would like : ";
    getline(cin, text);
    replaceNonCharactersWithSpace(text);
    splitText(text);

    return 0;
}

