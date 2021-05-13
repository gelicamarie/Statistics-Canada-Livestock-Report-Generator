#include "AnimalPercentChange.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

AnimalPercentChange::AnimalPercentChange() {
    AscBehaviour<float> *ascB = new AscBehaviour<float>;

    report = new ReportData<float>(ascB);
}
AnimalPercentChange::~AnimalPercentChange() {
    delete report;
}

void AnimalPercentChange::compute() {
    stringstream row;
    vector<int> year = years.getKeys();
    vector<string> animalTypes = animals.getKeys();
    vector<vector<float>> percentages;
    try {
        for (int i = 0; i < year.size(); ++i) {
            vector<Record *> temp = years[year[i]];
            vector<float> percentsPerYear;
            float animalsTotalDenominator = 0;
            denominator(year[i], animalsTotalDenominator);
            int k = 0;
            for (int j = 0; j < temp.size(); ++j) {
                if (temp[j]->getRegion() == "CAN") {
                    for (k; k < animalTypes.size(); ++k) {
                        float percent = 0.0;
                        if (temp[j]->getAnimalType() == animalTypes[k]) {
                            int totalAnimals = temp[j]->getNumAnimals();
                            float percent = (totalAnimals / animalsTotalDenominator) * 100;
                            percentsPerYear.push_back(percent);
                            ++k;
                            break;
                        } else {
                            percentsPerYear.push_back(percent);
                            ++k;
                            --j;
                            break;
                        }
                    }
                }
            }
            percentages.push_back(percentsPerYear);
        }

        vector<float> percentDifference;
        int columns = percentages[0].size();

        for (int i = 0; i < columns; ++i) {
            float difference = 0;
            for (int j = 0; j < percentages.size(); ++j) {
                difference = percentages[j][i] - difference;
            }
            percentDifference.push_back(difference);
        }
        percentages.push_back(percentDifference);
        formatData(percentages);
        printReport();
    } catch (const char *error) {
        cout << error << endl;
    }
}

void AnimalPercentChange::denominator(int y, float &d) const {
    try {
        vector<Record *> temp = regions["CAN"];
        float denominator = 0;

        for (int i = 0; i < temp.size(); ++i) {
            if (temp[i]->getYear() == y) {
                denominator += temp[i]->getNumAnimals();
            }
        }
        if (denominator == 0) {
            denominator = 1;
        }
        d = denominator;

    } catch (const char *error) {
        throw "Denominator calculation error.";
    }
}

void AnimalPercentChange::formatData(vector<vector<float>> data) const {
    stringstream row;
    int columns = data[0].size();
    vector<string> animalTypes = animals.getKeys();

    for (int i = 0; i < columns; ++i) {
        row << setw(15) << right << animalTypes[i];
        float key = 0;
        for (int j = 0; j < data.size(); ++j) {
            if (j == data.size() - 1) {
                key = data[j][i];
                row << setw(10) << right << setprecision(1) << fixed << showpos << data[j][i];
                report->add(key, row.str());
                break;
            }
            row << setw(10) << right << setprecision(1) << fixed << noshowpos << data[j][i];
        }
        row.str("");
    }
}

void AnimalPercentChange::formatHeader(string &header) const {
    stringstream h;
    vector<int> year = years.getKeys();
    h << setw(5) << " "
      << "PERCENTAGE CHANGE OF ANIMALS ";
    for (int i = 0; i < year.size(); ++i) {
        h << year[i] << " ";
    }
    h << endl
      << setw(2) << " "
      << "---------------------------------------------" << endl;

    h << setw(15) << " ";
    for (int i = 0; i < year.size(); ++i) {
        h << setw(10) << setfill(' ') << right << year[i];
    }

    h << setw(11) << right << "Change" << endl;
    header = h.str();
}

void AnimalPercentChange::printReport() const {
    ofstream outfile("AnimalPercentChange.txt", ios::trunc);
    if (!outfile) {
        cout << "Error:  could not open file" << endl;
        exit(1);
    }
    stringstream data;

    string h;
    formatHeader(h);

    data << h;
    data << *report;
    outfile << data.str();
    outfile.close();
    cout << data.str();
    report->clean();
}