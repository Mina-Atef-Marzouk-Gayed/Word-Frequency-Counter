#pragma once
#include <iostream>
using namespace std;

template <typename Type1,typename Type2>
class HashMap {
public:
    class Entry {
    public:
        Type1 key;
        Type2 value;
        Entry(const Type1& k, const Type2& v) : key(k), value(v) {}
    };

private:
    int capacity = 100;
    Entry* map;
    int hashFunc(Type1 key);

public:
    HashMap();
    ~HashMap();
    bool isEmpty();
    void put(Type1 key, Type2 value);
    void remove(Type key);
    void display();
    Type1 getVal(Type1 key);
};

template <typename Type1, typename Type2>
HashMap<Type1,Type2>::HashMap() : map(new Entry[capacity]) {}

template <typename Type1, typename Type2>
int HashMap<Type1, Type2>::hashFunc(Type1 key) {
    int index = 0;
    for (int i = 0; i < key.length(); i++) {
        index += static_cast<int>(key[i]);
    }
    return index % capacity;
}



template <typename Type1, typename Type2>
void HashMap<Type1, Type2>::put(Type1 key, Type2 value) {

    int hashedKeyIndex = hashFunc(key);
    map[hashedKeyIndex] = value;

}

template <typename Type1, typename Type2>
bool HashMap<Type1 , Type2>::isEmpty() {
    for (int i = 0; i < capacity; i++) {
        if (map[i].key.empty() && map[i].value != 0) {
            return false;
        }
    }
    return true;
}

template <typename Type1, typename Type2>
inline Type1 getVal(const Type1& key) {
    int index = hashFunc(key);
    return map[index].value;
}

template <typename Type1, typename Type2>
HashMap<Type1,Type2>::~HashMap() {
    delete[] map;
}
