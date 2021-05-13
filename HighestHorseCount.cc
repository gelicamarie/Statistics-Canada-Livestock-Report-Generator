#include "HighestHorseCount.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

HighestHorseCount::HighestHorseCount() {
    DescBehaviour<int> *descB = new DescBehaviour<int>;

    report = new ReportData<int>(descB);
}
HighestHorseCount::~HighestHorseCount() {
    delete report;
}

void HighestHorseCount::compute() {
    vector<string> animalType = animals.getKeys();
    vector<string> region = regions.getKeys();
    vector<Record *> maxRecords;

    try {
        for (int i = 0; i < region.size(); ++i) {
            if (region[i] == "CAN") continue;

            vector<Record *> temp = animals["Horses-Ponies"];
            bool found = false;
            int max = 0;
            Record *r;
            for (int j = 0; j < temp.size(); ++j) {
                if (temp[j]->getYear() != 2016 || temp[j]->getSubRegion() == "All") {
                    continue;
                }
                if (region[i] == temp[j]->getRegion()) {
                    if (max < temp[j]->getNumAnimals()) {
                        max = temp[j]->getNumAnimals();
                        r = temp[j];
                        found = true;
                    }
                }
            }
            if (found) {
                maxRecords.push_back(r);
            }
        }

        formatData(maxRecords);
        printReport();
    } catch (const char *error) {
        cout << error << endl;
    }
}

void HighestHorseCount::formatData(vector<Record *> maxRecords) const {
    stringstream row;
    vector<string> region = regions.getKeys();

    for (int i = 0; i < region.size(); ++i) {
        if (region[i] == "CAN") continue;
        bool found = false;
        for (int j = 0; j < maxRecords.size(); ++j) {
            if (region[i] == maxRecords[j]->getRegion()) {
                row << setw(10) << " " << setw(5) << left << region[i] << setw(35) << right << maxRecords[j]->getSubRegion() << setw(10) << right << maxRecords[j]->getNumAnimals();
                report->add(maxRecords[j]->getNumAnimals(), row.str());
                found = true;
                break;
            }
        }

        if (!found) {
            row << setw(10) << " " << setw(5) << left << region[i] << setw(35) << right << "  " << setw(10) << right << 0;
            report->add(0, row.str());
        }
        row.str("");
    }
}

void HighestHorseCount::printReport() const {
    ofstream outfile("HighestHorseCount2016.txt", ios::trunc);
    if (!outfile) {
        cout << "Error:  could not open file" << endl;
        exit(1);
    }

    stringstream data;

    data << setw(10) << " "
         << "SUB-REGION WITH MOST HORSES/PONIES BY REGION IN 2016" << endl;
    data << setw(8) << " "
         << "------------------------------------------------------" << endl;
    data << *report;

    outfile << data.str();
    outfile.close();

    cout << data.str();
    report->clean();
}