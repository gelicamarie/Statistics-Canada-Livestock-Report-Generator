/*
Report Data Class Template
Purpose : an object modeled to be an ordered collection of keys and formatted strings 
          representing each row. Also responsible for printing the report
Complex Attributes Functions:
    - ReportRow        : a class template responsible to hold the key value pair for each row
    - CompareBehaviour : the specific behaviour that will be responsible for dicting in what order/format the 
                         report row data will be ordered
    - void add(T, string) : responsible for adding a the key - value pair into the Report Row vector
                    in    : T : key value
                string    : formatted string

*/
#ifndef REPORTDATA_H
#define REPORTDATA_H

#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

#include "CompareBehaviour.h"
#include "Record.h"

template <class T>
class ReportData {
    template <class V>
    friend ostream &operator<<(ostream &, const ReportData<V> &);

   public:
    ReportData(CompareBehaviour<T> *);
    ~ReportData();
    void add(T key, string row);
    void clean();

   private:
    template <class V>
    class ReportRow {
       public:
        ReportRow(V k, string r) : key(k), row(r){};
        V key;
        string row;
    };
    vector<ReportRow<T>> rows;
    CompareBehaviour<T> *behaviour;
};

template <class T>
ReportData<T>::ReportData(CompareBehaviour<T> *b) : behaviour(b) {
}

template <class T>
ReportData<T>::~ReportData() {
    delete behaviour;
}

template <class T>
void ReportData<T>::add(T k, string r) {
    typename vector<ReportRow<T>>::iterator itr;
    //add err checking
    ReportRow<T> newRow(k, r);
    for (itr = rows.begin(); itr != rows.end(); ++itr) {
        if (behaviour->compare((*itr).key, k)) {
            rows.insert(itr, newRow);
            return;
        }
    }
    rows.insert(itr, newRow);
}

template <class T>
void ReportData<T>::clean() {
    rows.clear();
}

template <class V>
ostream &operator<<(ostream &output, const ReportData<V> &r) {
    for (int i = 0; i < r.rows.size(); ++i) {
        output << r.rows.at(i).row << endl;
    }

    return output;
}

#endif