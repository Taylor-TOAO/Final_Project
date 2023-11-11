//D.h
#ifndef COLLEGE_FUND_CALCULATOR_H
#define COLLEGE_FUND_CALCULATOR_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

class CollegeFundCalculator {
private:
    double D_Principle, D_IR,networth;
    vector<double> months, years;
    int total;
public:
    CollegeFundCalculator();
    void getInput();
    void readDataFromFile(const string& file);
    void calculateCollegeFund();
    void generateOutputToFile(const string& username);
};

#endif