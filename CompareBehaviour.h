/*
Compare Behaviour Template Class (Abstract)
Purpose: creates objects responsible for comparing different variables/objects, and compares these values
         by a specific behaviour defined in the compare function

Concrete Derived Classes from Compare Behaviour:
   1. AscBehaviour
      Purpose: responsible for creating an object that uses the compare(T,T) function
               and compares the two parameters by ascending order

   2. DescBehaviour
      Purpose: responsible for creating an object that uses the compare(T,T) function
               and compares the two parameters by descending order

   
*/
#ifndef COMPAREBEHAVIOUR_H
#define COMPAREBEHAVIOUR_H

#include <iostream>
using namespace std;
#include <cstdlib>

template <class T>
class CompareBehaviour {
   public:
    virtual bool compare(T, T) = 0;

   protected:
};

template <class T>
class AscBehaviour : public CompareBehaviour<T> {
   public:
    virtual bool compare(T, T);

   protected:
};

template <class T>
class DescBehaviour : public CompareBehaviour<T> {
   public:
    virtual bool compare(T, T);

   protected:
};

template <class T>
bool AscBehaviour<T>::compare(T x, T y) {
    return (x > y);
}

template <class T>
bool DescBehaviour<T>::compare(T x, T y) {
    return (x < y);
}
#endif