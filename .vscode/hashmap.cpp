#include "HashMap.h"
using namespace std;

int main() {
    HashMap<std::string, int> map;

    // Add key-value pairs to the map
    map.put("apple", 5);
    map.put("banana", 10);
    map.put("orange", 7);

    // Display the contents of the map
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

    return 0;
}