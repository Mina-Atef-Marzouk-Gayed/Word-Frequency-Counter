#pragma once
#include <iostream>
#include<iomanip>

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
    void sortMapDescending();

public:
    HashMap();
    ~HashMap();
    HashMap(const HashMap& other);
    bool isEmpty();
    void put(KeyType key);
    void remove(KeyType key);
    void display();
    ValueType getVal(KeyType key);
};

template <typename KeyType, typename ValueType>
HashMap<KeyType, ValueType>::HashMap() : map(new Entry[capacity]) {}

template <typename KeyType, typename ValueType>
HashMap<KeyType, ValueType>::HashMap(const HashMap& other) : capacity(other.capacity), map(new Entry[capacity]) {
    for (int i = 0; i < capacity; i++) {
        map[i] = other.map[i];
    }
    sortMapDescending();
}

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
        if (map[i].key == KeyType()) {
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
        map[hashedKeyIndex].key = KeyType();
    }

}
template <typename KeyType, typename ValueType>
void HashMap<KeyType, ValueType>::sortMapDescending() {
    for (int i = 0; i < capacity - 1; i++) {
        for (int j = i + 1; j < capacity; j++) {
            if (map[i].value < map[j].value) {
                swap(map[i], map[j]);
            }
        }
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

template <typename KeyType, typename ValueType>
void HashMap<KeyType, ValueType>::display() {
    cout << left << setw(20) << "Key" << setw(20) << "Value" << endl;
    cout << "----------------------------------" << endl;

    for (int i = 0; i < capacity; i++)
    {
        if (map[i].key == KeyType())
            continue;
        cout << left << setw(20) << map[i].key << setw(20) << map[i].value << endl;
    }
}

template <typename KeyType, typename ValueType>
HashMap<KeyType, ValueType>::~HashMap() {

    delete[] map;
}
