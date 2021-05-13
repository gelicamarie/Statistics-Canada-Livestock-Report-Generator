/*
Farm Distribution Concrete Class 
    - base class ReportGenerator
Purpose: creates a report listing the regional percentage breakdown of farms hosting each animal types for 2016
         
Complex attributes or functions:
    -vitual void compute()
              : a polymorphic function responsible for computing the results for this
              specific report. Calculated data is stored in vectors and is passed on to
              formatData
    -void formatData(vector<string>, vector<vector<float>>)
              : responsible for formatting the computed data to its proper report layout and adding it
                to the ReportData object class
        in    : vector<string> stores the regions in order of how the data is calculated
        in    : vector<vector<float>> stores the vector of all calculated data for each animal
                for each region, indexes corresponds to the vector<string> of region
    -void animalDenominators(vector<float> &) 
              : responsible for calculating the totals for each animalType in each region, used for compute
        inout : vector<float> that will store the resulting floats
              

*/
#ifndef FARMDISTRIBUTION_H
#define FARMDISTRIBUTION_H

#include "ReportGenerator.h"

class FarmDistribution : public ReportGenerator {
   public:
    FarmDistribution();
    virtual ~FarmDistribution();
    virtual void compute();

   private:
    ReportData<float> *report;
    void printReport() const;
    void formatData(vector<string>, vector<vector<float>>) const;
    void formatHeader(string &) const;
    void animalDenominators(vector<int> &) const;
};

#endif