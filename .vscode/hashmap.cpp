#include <iostream>
#include <sstream>
#include "hashmap.h"
using namespace std;

void replaceNonCharactersWithSpace(string& text) {
    for (char& c : text) {
        if (!isalnum(c)) {
            c = ' ';
        }
    }
}
int splitTextCounter(const string text) {
    int wordCounter = 0;
    istringstream separate(text);
    string word;
    while (separate >> word) {
        wordCounter++;
    }
    return wordCounter+59;
}
void splitText(string& text)
{   
    HashMap<string, int> mapping(splitTextCounter(text));
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
