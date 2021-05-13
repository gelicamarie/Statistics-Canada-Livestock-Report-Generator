/*
Control Class
Purpose: the control class allows the user to interact with the program. 
         It intitializes the data used in the program
Complex attributes or functions:
    ReportGenerator *records            : object will be responsible for storing and initializing the data 
    vector<ReportGenerator *> reports;  : holds an array of the different reports generated in this program
    
*/
#ifndef CONTROL_H
#define CONTROL_H

#include <cstdlib>
#include <vector>
using namespace std;

#include "ReportGenerator.h"
#include "View.h"

class Control {
   public:
    Control();
    ~Control();
    void launch() const;

   private:
    View *view;
    ReportGenerator *records;
    vector<ReportGenerator *> reports;
};

#endif
