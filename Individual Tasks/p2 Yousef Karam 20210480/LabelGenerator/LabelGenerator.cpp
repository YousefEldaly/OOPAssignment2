//
// Created by Youssef on 11/10/2022.
//
#include "LabelGenerator.h"
#include <iostream>
#include <fstream>
using namespace std;

LabelGenerator::LabelGenerator(string lp, int lc) {
        labelPrefix = lp;
        labelCounter = lc;
    }

void LabelGenerator::nextLabel(){
    cout << labelPrefix << " " << labelCounter << " " ;
    labelCounter++;
};
FileLabelGenerator::FileLabelGenerator(string lp, int lc, string fn) : LabelGenerator(lp, lc) {
    fileName = fn;

}
void FileLabelGenerator :: nextLabel(){
    LabelGenerator::nextLabel();
    ifstream file;
    file.open(fileName, ios::in);
    for (int i = 0; i < line_counter; i++) {
        getline(file, line);
    }
    cout << line << endl;
    line_counter++;


};


