/*
Highest Horse Count Concrete Class 
    - base class ReportGenerator
Purpose: creates a report listing the sub region for each region with the highest number of horses/ponies in 2016      
Complex attributes or functions:
    -vitual void compute()
              : a polymorphic function responsible for computing the results for this
              specific report. Calculated data is stored in vectors and is passed on to
              formatData
    -void formatData(vector<Record *>)
              : responsible for formatting the computed data to its proper report layout and adding it
                to the ReportData object class
        in    : vector<Record *> from compute: this vector contains a pointer to the records of each sub region
                (for each region) with the highest horses/ponies count
    -
              

*/

#ifndef HIGHESTHORSECOUNT_H
#define HIGHESTHORSECOUNT_H

#include "ReportGenerator.h"

class HighestHorseCount : public ReportGenerator {
   public:
    HighestHorseCount();
    virtual ~HighestHorseCount();
    virtual void compute();

   private:
    ReportData<int> *report;
    void formatData(vector<Record *>) const;
    void printReport() const;
};

#endif