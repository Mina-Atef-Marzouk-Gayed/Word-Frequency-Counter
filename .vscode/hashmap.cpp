#include <iostream>
#include <sstream>
#include "hashmap.h"
using namespace std;

int main() {
    HashMap<std::string, int> map;



    HashMap<string, int> mapping;
    string text;
    cout << "Please input any text you would like : ";
    getline(cin, text);
    istringstream separate(text);
    string word;
    while (separate >> word) {
        mapping.put(word);
    }
    mapping.display();
    cout<<mapping.getVal("LOL");



    return 0;
}
