/*
Animal Percent Change Concrete Class 
    - base class ReportGenerator
Purpose: creates a report listing of the percentage breakdown of animals in Canada, and includes
         the percent change for each animal type between two census years (2011 and 2016)
         
Complex attributes or functions:
    -vitual void compute()
              : a polymorphic function responsible for computing the results for this
              specific report. Calculated data is stored in vectors and is passed on to
              formatData
    -void formatData(vector<vector<float>>)
              : responsible for formatting the computed data to its proper report layout and adding it
                to the ReportData object class
        in    : 2D float vector (from compute) this vector contains a vector of the results for each animal type in each region
    -float denominator(int year)
              : responsible for calculating the total animals in a region for a specific year (used in compute)
        in    : year, serves as a key to grab the data from the right year
              

*/
#ifndef ANIMALPERCENTCHANGE_H
#define ANIMALPERCENTCHANGE_H

#include "ReportGenerator.h"

class AnimalPercentChange : public ReportGenerator {
   public:
    AnimalPercentChange();
    virtual ~AnimalPercentChange();
    virtual void compute();

   private:
    ReportData<float> *report;
    void printReport() const;
    void formatData(vector<vector<float>>) const;
    void formatHeader(string &) const;
    void denominator(int, float &) const;
};

#endif