/*
Map Template Class
Purpose : to create a map object using two parallel vectors, 
          stores a collection of keys and collection of values
Complex atrributetes & functions:
    vector<Record*>& operator[](T)
            overrides the [] operator. This returns the values in the index corresponding to the key vector index
    void checkKey(T)
            checks if a key exists or not
        in: the Key to be checked
*/
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

#include "Record.h"

template <class T>
class Map {
   public:
    Map();
    vector<Record*>& operator[](T);
    void add(T, Record*);
    int getKeysSize();
    vector<T>& getKeys();

   private:
    vector<T> keys;
    vector<vector<Record*>> values;
    void checkKey(T) const;
};

template <class T>
Map<T>::Map() {
}

template <class T>
int Map<T>::getKeysSize() {
    return keys.size();
}

template <class T>
vector<T>& Map<T>::getKeys() {
    return keys;
}

template <class T>
void Map<T>::add(T k, Record* v) {
    for (int i = 0; i < keys.size(); ++i) {
        if (k == keys.at(i)) {
            values.at(i).push_back(v);
            return;
        }
    }

    keys.push_back(k);
    vector<Record*> temp;
    temp.push_back(v);
    values.push_back(temp);
}

template <class T>
vector<Record*>& Map<T>::operator[](T k) {
    bool found = false;

    int x = -1;
    for (int i = 0; i < keys.size(); ++i) {
        if (keys.at(i) == k) {
            x = i;
            found = true;
            break;
        }
    }

    if (found == false) {
        throw "Error: Key not found.";
    }

    return values.at(x);
}
