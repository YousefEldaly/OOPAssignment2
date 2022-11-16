//
// Created by Youssef on 11/10/2022.
//

#include <iostream>
using namespace std;
#ifndef MAIN_CPP_LABELGENERATOR_H
#define MAIN_CPP_LABELGENERATOR_H

class LabelGenerator {
private:
    string labelPrefix;
protected:
    int labelCounter;
public:
    LabelGenerator();
    LabelGenerator(string lp, int lc);
    void nextLabel();
};
class FileLabelGenerator : public LabelGenerator {
private:
    string fileName;
    string line;
    int line_counter = 1;
public:
    FileLabelGenerator();
    FileLabelGenerator(string lp, int lc, string fn);
    void nextLabel();
};
#endif //MAIN_CPP_LABELGENERATOR_H
