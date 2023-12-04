#pragma once
#include <iostream>
#include<iomanip>
#include"Entry.h"
using namespace std;


class HashMap {


private:
    int capacity;
    Entry* map;
    int hashFunc(string key);
    void sortMapDescending();

public:
    HashMap();
    HashMap(int sizeofWords);
    ~HashMap();
    HashMap(const HashMap& other);
    bool isEmpty();
    void put(string key);
    void remove(string key);
    void display();
    int getVal(string key);

};

//
//HashMap::HashMap() :capacity(100), map(new Entry[capacity]) {}
//
//
//HashMap::HashMap(int sizeofWords) :capacity(sizeofWords),map(new Entry[capacity]){}
//
//
//HashMap::HashMap(const HashMap& other) : capacity(other.capacity), map(new Entry[capacity]) {
//    for (int i = 0; i < capacity; i++) {
//        map[i] = other.map[i];
//    }
//    sortMapDescending();
//}
//
//
//int HashMap::hashFunc(string key) {
//    int index = 0;
//    for (int i = 0; i < key.length(); i++) {
//        index += static_cast<int>(tolower(key[i]));
//    }
//    return index % capacity;
//}
//
//
//bool HashMap::isEmpty() {
//    for (int i = 0; i < capacity; i++) {
//        if (map[i].key == string()) {
//            return false;
//        }
//    }
//    return true;
//}
//
//void HashMap::put(string key) {
//    int index = hashFunc(key);
//    if (map[index].key == key) {
//        map[index].value++;
//    }
//    else {
//        map[index].key = key;
//        map[index].value++;
//    }
//}
//
//
//void HashMap::remove(string key) {
//
//    int hashedKeyIndex = hashFunc(key);
//
//    if (isEmpty()) {
//        cerr << "[WARNING] : Your hashmap is empty , so the following operation cannot be perforemd .";
//        exit(0);
//    }
//    if (map[hashedKeyIndex].key != key) {
//        cerr << "[WARNING] : Key doesn't exist , cancelling operation .";
//        exit(0);
//    }
//    else {
//        map[hashedKeyIndex].key = string();
//    }
//
//}
//
//void HashMap::sortMapDescending() {
//    for (int i = 0; i < capacity - 1; i++) {
//        for (int j = i + 1; j < capacity; j++) {
//            if (map[i].value < map[j].value) {
//                swap(map[i], map[j]);
//            }
//        }
//    }
//}
//
//
//inline int HashMap::getVal(string key)
//{
//    int index = hashFunc(key);
//    if (map[index].value < 1) {
//        cerr << "The key NOT found";
//        exit(0);
//    }
//    else {
//        return map[index].value;
//    }
//}
//
//
//void HashMap::display() {
//    cout << left << setw(20) << "Key" << setw(20) << "Value" << endl;
//    cout << "----------------------------------" << endl;
//
//    for (int i = 0; i < capacity; i++)
//    {
//        if (map[i].key == string())
//            continue;
//        cout << left << setw(20) << map[i].key << setw(20) << map[i].value << endl;
//    }
//}
//
//
//HashMap::~HashMap() {
//
//    delete[] map;
//}

