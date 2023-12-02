#include <iostream>
#include <sstream>
#include "hashmap.h"
using namespace std;

int main() {
    HashMap<std::string, int> map;

    map.put("BMW");
    map.put("LANCER");
    map.put("KIA");

    map.display();

    // Get the value for a specific key
    std::cout << "Value for 'banana': " << map.getVal("banana") << std::endl;

    // Remove a key-value pair from the map
    map.remove("apple");

    // Check if the map is empty
    if (map.isEmpty()) {
        std::cout << "Map is empty" << std::endl;
    }
    else {
        std::cout << "Map is not empty" << std::endl;
    }

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



    return 0;
}
