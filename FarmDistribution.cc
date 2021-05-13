#include "FarmDistribution.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

FarmDistribution::FarmDistribution() {
    DescBehaviour<float> *descB = new DescBehaviour<float>;
    report = new ReportData<float>(descB);
}
FarmDistribution::~FarmDistribution() {
    delete report;
}

void FarmDistribution::compute() {
    vector<vector<float>> dataPerRegion;
    vector<string> regionKeys = regions.getKeys();
    vector<string> animalTypes = animals.getKeys();
    float totalDenominator = 0;
    vector<int> d;
    animalDenominators(d);
    for (int i = 0; i < d.size(); ++i) {
        totalDenominator += d[i];
    }

    try {
        for (int i = 0; i < regionKeys.size(); ++i) {
            if (regionKeys[i] == "CAN") continue;
            vector<Record *> temp = regions[regionKeys[i]];
            vector<float> percentages;
            float totalFarmsPerRegion = 0;
            int k = 0;

            for (int j = 0; j < temp.size(); ++j) {
                if (temp[j]->getYear() == 2016 && temp[j]->getSubRegion() == "All") {
                    float numerator = 0;
                    int denominator = 1;
                    for (k; k < animalTypes.size(); ++k) {
                        if (temp[j]->getAnimalType() == animalTypes[k]) {
                            numerator = temp[j]->getNumFarms();
                            denominator = d[k];
                            totalFarmsPerRegion += numerator;
                            ++k;
                            break;
                        }
                        ++k;
                        --j;
                        break;
                    }

                    percentages.push_back((numerator / denominator) * 100);
                }
            }
            percentages.push_back((totalFarmsPerRegion / totalDenominator) * 100);
            dataPerRegion.push_back(percentages);
            totalFarmsPerRegion = 0;
        }
        formatData(regionKeys, dataPerRegion);
        printReport();
    } catch (const char *error) {
        cout << error << endl;
    }
}

void FarmDistribution::animalDenominators(vector<int> &denominators) const {
    vector<int> d;
    vector<string> regionKeys = regions.getKeys();
    vector<string> animalTypes = animals.getKeys();
    try {
        for (int i = 0; i < animalTypes.size(); ++i) {
            int tempD = 0;
            for (int j = 0; j < regionKeys.size(); ++j) {
                if (regionKeys[j] == "CAN") continue;
                vector<Record *> temp = regions[regionKeys[j]];
                for (int k = 0; k < temp.size(); ++k) {
                    if (temp[k]->getYear() == 2016 && temp[k]->getSubRegion() == "All" && temp[k]->getAnimalType() == animalTypes[i]) {
                        tempD += temp[k]->getNumFarms();
                    }
                }
            }

            d.push_back(tempD);
        }

        denominators = d;
    } catch (const char *error) {
        throw "Denominator calculation error.";
    }
}

void FarmDistribution::formatData(vector<string> region, vector<vector<float>> data) const {
    stringstream row;
    for (int i = 0; i < region.size(); ++i) {
        if (region[i] == "CAN") continue;
        row << setw(4) << left << region[i];
        int k = 0;
        for (int j = 0; j < data[i - 1].size(); ++j) {
            row << setw(9) << setprecision(1) << fixed << right << data[i - 1][j] << " ";
            k = j;
        }
        float key = data[i - 1][k];
        report->add(key, row.str());
        row.str("");
    }
}

void FarmDistribution::formatHeader(string &header) const {
    stringstream top;
    stringstream bottom;
    string delimeter = "-";

    top << setw(4) << left << " ";
    bottom << setw(4) << left << " ";
    vector<string> animalsRow = animals.getKeys();
    for (int i = 0; i < animalsRow.size(); ++i) {
        size_t pos = animalsRow[i].find(delimeter);
        if (pos > animalsRow[i].size()) {
            top << setw(10) << right << animalsRow[i];
            bottom << setw(10) << " ";
        } else {
            top << setw(10) << right << animalsRow[i].substr(0, pos) + "/";
            bottom << setw(10) << right << animalsRow[i].substr(pos + 1, animalsRow[i].size());
        }
    }
    top << setw(10) << right << "Total";

    header = top.str() + "\n" + bottom.str() + "\n";
}

void FarmDistribution::printReport() const {
    ofstream outfile("FarmDistribution2011-2016.txt", ios::trunc);
    if (!outfile) {
        cout << "Error:  could not open file" << endl;
        exit(1);
    }

    stringstream data;
    vector<string> regionkeys = regions.getKeys();
    string h;
    formatHeader(h);
    data
        << setw(35) << " "
        << "PERCENTAGE OF FARMS BY REGION 2016" << endl;
    data << setw(32) << " "
         << "-------------------------------------" << endl;
    data << h;

    data << *report << endl;
    cout << data.str();
    outfile << data.str();
    outfile.close();

    report->clean();
}