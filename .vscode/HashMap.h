#pragma once
#include <iostream>
using namespace std;


template <typename KeyType, typename ValueType>
class HashMap {
public:
    class Entry {
    public:
        KeyType key;
        ValueType value;
        Entry() : key(), value() {}
        Entry(const KeyType& k, const ValueType& v) : key(k), value(1) {}
    };

private:
    int capacity = 100;
    Entry* map;
    int hashFunc(KeyType key);
   

public:
    HashMap();
    ~HashMap();
    bool isEmpty();
    void put(KeyType key);
    void remove(KeyType key);
    void display();
    ValueType getVal(KeyType key);
    void getHighest();
};

template <typename KeyType, typename ValueType>
HashMap<KeyType, ValueType>::HashMap() : map(new Entry[capacity]) {}

template <typename KeyType, typename ValueType>
int HashMap<KeyType, ValueType>::hashFunc(KeyType key) {
    int index = 0;
    for (int i = 0; i < key.length(); i++) {
        index += static_cast<int>(tolower(key[i]));
    }
    return index % capacity;
}

template <typename KeyType, typename ValueType>
bool HashMap<KeyType, ValueType>::isEmpty() {
    for (int i = 0; i < capacity; i++) {
        if (!map[i].key.empty()) {
            return false;
        }
    }
    return true;
}
template <typename KeyType, typename ValueType>
void HashMap<KeyType, ValueType>::put(KeyType key) {
    int index = hashFunc(key);
    if (map[index].key == key) {
        map[index].value++;
    }
    else {
        map[index].key = key;
        map[index].value++;
    }
}


template <typename KeyType, typename ValueType>
void HashMap<KeyType, ValueType>::remove(KeyType key) {

    int hashedKeyIndex = hashFunc(key);

    if (isEmpty()) {
        cerr << "[WARNING] : Your hashmap is empty , so the following operation cannot be perforemd .";
        exit(0);
    }
    if (map[hashedKeyIndex].key != key) {
        cerr << "[WARNING] : Key doesn't exist , cancelling operation .";
        exit(0);
    }
    else {
        map[hashedKeyIndex].key.clear();
    }

}

template<typename KeyType, typename ValueType>
inline ValueType HashMap<KeyType, ValueType>::getVal(KeyType key)
{
    int index = hashFunc(key);
    if (map[index].value < 1) {
        cerr << "The key NOT found";
        exit(0);
    }
    else {
        return map[index].value;
    }
}

template<typename KeyType, typename ValueType>
 void HashMap<KeyType, ValueType>::getHighest()
{
     int bigval =0; // 1st word highest count
    for (int i = 1; i < capacity; i++) {
        if (map[bigval].value < map[i].value) {

            bigval = i;
        }
        
}
   
    cout << "Most frequently used word is: " << map[bigval].key<<" repeated "<<map[bigval].value<<" times.\n";


  
}

template <typename KeyType, typename ValueType>
void HashMap<KeyType, ValueType>::display() {
    for (int i = 0; i < capacity; i++)
    {
        if (map[i].key.empty())
            continue;
        cout << "Key: " << map[i].key << ", Value: " << map[i].value << endl;

    }
    getHighest();
}

template <typename KeyType, typename ValueType>
HashMap<KeyType, ValueType>::~HashMap() {

    delete[] map;
}
