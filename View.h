/*
View Class
Purpose: to prompt user for their choices and read in their choice
*/
#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <string>
using namespace std;

class View {
   public:
    void showMenu(int&) const;
    void printStr(string) const;
    void readInt(int&) const;
    void readStr(string&) const;
};

#endif
