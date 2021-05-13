#include "Control.h"

#include <iostream>
using namespace std;
#include <string>

#include "AnimalPercentChange.h"
#include "FarmDistribution.h"
#include "HighestHorseCount.h"
#include "ReportGenerator.h"

Control::Control() {
    FarmDistribution *report1 = new FarmDistribution();
    AnimalPercentChange *report2 = new AnimalPercentChange();
    HighestHorseCount *report3 = new HighestHorseCount();

    reports.push_back(report1);
    reports.push_back(report2);
    reports.push_back(report3);
}
Control::~Control() {
    for (int i = 0; i < reports.size(); ++i) {
        delete reports[i];
    }
}

void Control::launch() const {
    records->initRecords();
    int num = 1;

    while (num != 0) {
        view->showMenu(num);
        if (num == 1) {
            reports[0]->compute();
        } else if (num == 2) {
            reports[1]->compute();
        } else if (num == 3) {
            reports[2]->compute();
        }
    }

    records->cleanup();
}
