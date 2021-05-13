/*
Purpose: 
    The purpose of this program is to generate a set of different reports based on the data provided 
    by Statistics Canada's Other livestock census(2011-2016). There are 3 reports for this program:
        1. A report listing the percentage breakdown of farms for each region and for each animal in 2016.
        2. A report listing the percent change of each animal in Canada from 2011 - 2016
        4. A report listing the sub region for each region that has the most Horses/Ponies
    The program was designed to accomodate scalability for each reports. 
Usage: 
    - command line arguments:
        a. make final , ./final
        b. make final2
        c. make clean
        
Author: Angelica Marie Turla
*/

#include "Control.h"

int main() {
    Control control;
    control.launch();
}