#include <iostream>
#include "LabelGenerator.h"

int main() {
//    LabelGenerator figureNumbers("Figure", 1);
//    LabelGenerator pointNumbers("Point", 0);
//    figureNumbers.nextLabel();
//    figureNumbers.nextLabel();
//    figureNumbers.nextLabel();
//    pointNumbers.nextLabel();
//    pointNumbers.nextLabel();
//    pointNumbers.nextLabel();
    FileLabelGenerator figureNumbers("Figure ", 1, "file.txt");
    figureNumbers.nextLabel();
    figureNumbers.nextLabel();
    figureNumbers.nextLabel();
    figureNumbers.nextLabel();
    figureNumbers.nextLabel();
    figureNumbers.nextLabel();

    return 0;
}
