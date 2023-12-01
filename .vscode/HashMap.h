#pragma once
#include <iostream>

template <typename KeyType, typename ValueType>

class HashMap {
public:
    class Entry {
    public:
        KeyType key;
        ValueType value;
        Entry(const KeyType& k, const ValueType& v) : key(k), value(v) {}
    };

private:
    int capacity = 100;
    Entry* map;
    int hashFunc(KeyType key);

public:
    HashMap();
    ~HashMap();
    bool isEmpty();
    void put(KeyType key, ValueType value);
    void remove(KeyType key);
    void display();
    ValueType getVal(KeyType key);
};

template <typename KeyType, typename ValueType>

HashMap<KeyType, ValueType>::HashMap() : map(new Entry[capacity]) {}

template <typename KeyType, typename ValueType>
int HashMap<KeyType, ValueType>::hashFunc(KeyType key) {
    int index = 0;
    for (int i = 0; i < key.length(); i++) {
        index += static_cast<int>(key[i]);
    }
    return index % capacity;
}

template <typename KeyType, typename ValueType>
bool HashMap<KeyType, ValueType>::isEmpty() {

    for (int i = 0; i < capacity; i++) {
        if (map[i].key.empty() && map[i].value != 0) {
            return false;
        }
    }
    return true;
}
template <typename KeyType, typename ValueType>
void HashMap<KeyType, ValueType>::put( KeyType key, ValueType value) {
    int index = hashFunc(key);
    map[index].key = key;
    map[index].value = value;
}

template <typename KeyType, typename ValueType>
void HashMap<KeyType , ValueType>::remove(KeyType key) {

    int hashedKeyIndex = hashFunc(key);

    if (isEmpty) {
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

template <typename KeyType, typename ValueType>
inline KeyType getVal(const KeyType& key) {
    int index = hashFunc(key);
    if (map[index].value == 0)
        cerr << "The key NOT found";
    else
        return map[index].value;
}
template <typename KeyType, typename ValueType>
HashMap<KeyType, ValueType>::~HashMap() {

    delete[] map;
}
