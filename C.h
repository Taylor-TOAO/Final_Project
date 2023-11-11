//C.h
#ifndef MORTGAGE_CALCULATOR_H
#define MORTGAGE_CALCULATOR_H
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

class MortgageCalculator {

private:
    double principle, interest_rate, loan_term, monthly_payment;

public:
    MortgageCalculator(const string& file, const string& username);
    void loadInputDataFromFile(const string& file);
    void CalculateMortgage();
    void generateOutput(const string& username);
};

#endif // MORTGAGE_CALCULATOR_H