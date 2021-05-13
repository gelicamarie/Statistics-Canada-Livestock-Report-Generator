#include "Record.h"

#include <iomanip>

Record::Record(int yr, string r, string sR, string a, int numF, int numA)
    : year(yr), region(r), subRegion(sR), animalType(a), numFarms(numF), numAnimals(numA) {
}
Record::~Record() {
}
int Record::getYear() const {
    return year;
}
string Record::getRegion() const {
    return region;
}
string Record::getSubRegion() const {
    return subRegion;
}
string Record::getAnimalType() const {
    return animalType;
}

int Record::getNumFarms() const {
    return numFarms;
}

int Record::getNumAnimals() const {
    return numAnimals;
}
ostream&
operator<<(ostream& output, Record& r) {
    output << setfill(' ') << setw(8) << left << r.year
           << setfill(' ') << setw(8) << left << r.region
           << setfill(' ') << setw(50) << left << r.subRegion
           << setfill(' ') << setw(20) << left << r.animalType
           << setfill(' ') << setw(8) << left << r.numFarms
           << setfill(' ') << setw(8) << left << r.numAnimals;

    return output;
}