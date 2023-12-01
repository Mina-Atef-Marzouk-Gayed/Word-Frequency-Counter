#pragma once
#include <iostream>

template <typename Type>
class HashMap {
public:
    class Entry {
    public:
        Type key;
        Type value;
        Entry(const Type& k, const Type& v) : key(k), value(v) {}
    };

private:
    int capacity = 100;
    Entry* map;
    int hashFunc(Type key);

public:
    HashMap();
    ~HashMap();
    bool isEmpty();
    void put(Type key, Type value);
    void remove(Type key);
    void display();
    Type getVal(Type key);
};

template <typename Type>
HashMap<Type>::HashMap() : map(new Entry[capacity]) {}

template <typename Type>
int HashMap<Type>::hashFunc(Type key) {
    int index = 0;
    for (int i = 0; i < key.length(); i++) {
        index += static_cast<int>(key[i]);
    }
    return index % capacity;
}

template <typename Type>
bool HashMap<Type>::isEmpty() {
    for (int i = 0; i < capacity; i++) {
        if (map[i].key.empty() && map[i].value != 0) {
            return false;
        }
    }
    return true;
}

template<typename Type>
inline Type getVal(const Type& key) { 
    int index = hashFunc(key);
    return map[index].value;
}

template <typename Type>
HashMap<Type>::~HashMap() {
    delete[] map;
}
