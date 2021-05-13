/*
Record Class
Purpose: to create an object that stores information about each data in the frams.dat and initialize
         each corresponding attributes. This object will hold the statistical information about the farm and animal
         statistics for a given year, region, sub region, and animal type.
Complex Attributes & Functions:
    ostream& operator<<(ostream&, Record&)
         overridden operator for printing the object in a proper format
*/
#ifndef RECORD_H
#define RECORD_H

#include <string>
using namespace std;

class Record {
    friend ostream& operator<<(ostream&, Record&);

   public:
    Record(int, string, string, string, int = 0, int = 0);
    ~Record();
    int getYear() const;
    string getRegion() const;
    string getSubRegion() const;
    string getAnimalType() const;
    int getNumFarms() const;
    int getNumAnimals() const;

   private:
    int year;
    string region;
    string subRegion;
    string animalType;
    int numFarms;
    int numAnimals;
};

#endif
