/*
Report Generator : Base Class for all the reports
Purpose : responsible for initializing and storing the data used for report generation. It is the base
          class responsible for report generation
Complex Attributes and Functions :
        - void initRecords()     : responsible for reading in the file and storing the data in the collection of Record pointers
                                   and all the different Map data members
        - virtual void compute() : implemented by each derived classes, concrete class to generate a report
*/
#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H

#include <string>
#include <vector>
using namespace std;

#include "Map.h"
#include "ReportData.h"

class ReportGenerator {
   public:
    ReportGenerator();
    virtual ~ReportGenerator();
    static void initRecords();

    virtual void compute() = 0;

    static void cleanup();

   protected:
    static vector<Record *> records;
    static Map<int> years;
    static Map<string> regions;
    static Map<string> animals;
};

#endif
