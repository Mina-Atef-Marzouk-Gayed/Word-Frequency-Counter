#pragma once
using namespace std;
template <typename Type>


class HashMap
{
private:
const int capacity =20;
  
   Type map[capacity];
   int hashFunc(Type key);
public:
    HashMap();
    ~HashMap();
    void put(Type key);
    void remove(Type key);
    void display();
    Type getVal(Type key)
    bool isEmpty();


};
template <typename Type>
int HashMap<Type>:: hashFunc(Type key){
int index = hash<Type>()(key);  //hashing function


return index %capacity;
    
}
template <typename Type>
bool HashMap<Type>::isEmpty(){
int sum= 0;
for (int i= 0; i<capacity ; i++){


sum+= map[i];

}
if(!sum) return true;

return false;

}
