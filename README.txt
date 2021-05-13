Author: Angelica Marie Turla
101143518
COMP 2404 - Final Project : Statistics Canada's Other livestock report generator

Purpose: 
    The purpose of this program is to generate a set of different reports based on the data provided 
    by Statistics Canada's Other livestock census(2011-2016). There are 3 reports for this program:
        1. A report listing the percentage breakdown of farms for each region and for each animal in 2016.
        2. A report listing the percent change of each animal in Canada from 2011 - 2016
        4. A report listing the sub region for each region that has the most Horses/Ponies
    The program was designed to accommodate scalability for each reports. 

Source Files:
    AnimalPercentChange.cc
    Control.cc
    FarmDistribution.cc
    HighestHorseCount.cc
    main.cc
    Record.cc
    ReportGenerator.cc
    View.cc

Header Files:
    AnimalPercentChange.has
    CompareBehaviour.h
    Control.h
    FarmDistribution.h 
    HighestHorseCount.h
    Map.h
    Record.h
    ReportData.h 
    ReportGenerator.h 
    View.h 

Launching Instructions:
1. Open terminal and locate comp2404Final using command 'cd'
2. A make file was created for easier compilation, there are two choices:
    a.  make final 
        - run 'make final' : this will compile all the files in the program 
        - run './final' after compilation : this will execute the program
        - if you would like to use valgrind, run 'valgrind ./final'
    
    b. make final2 (more efficient with valgrind) 
        - run 'make final2' : this will compile all the files and run the program with valgrind all together
    

All Done!
