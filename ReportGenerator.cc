#include "ReportGenerator.h"

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <sstream>

#include "ReportData.h"

vector<Record *> ReportGenerator::records;

Map<int> ReportGenerator::years;

Map<string> ReportGenerator::regions;

Map<string> ReportGenerator::animals;

ReportGenerator::ReportGenerator() {
}
ReportGenerator::~ReportGenerator() {
}

void ReportGenerator::initRecords() {
    ifstream infile("farms.dat", ios::in);
    ostream_iterator<Record> outItr(cout);

    if (!infile) {
        cout << "Error: could not open file" << endl;
        exit(1);
    }

    int year, numFarms, numAnimals;
    string region, subRegion, animalType;

    while (infile >> year >> region >> subRegion >> animalType >> numFarms >> numAnimals) {
        Record *r = new Record(year, region, subRegion, animalType, numFarms, numAnimals);
        records.push_back(r);
        years.add(year, r);
        regions.add(region, r);
        animals.add(animalType, r);
    }
}

void ReportGenerator::cleanup() {
    for (int i = 0; i < records.size(); ++i) {
        delete records[i];
    }
}
