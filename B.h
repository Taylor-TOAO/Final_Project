//B.h
#ifndef INVESTMENT_CALCULATOR_H
#define INVESTMENT_CALCULATOR_H

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

class InvestmentCalculator {

private:
    double shares, price, comm, annreturn, years, amount, acomm, totalA, total;

public:
    InvestmentCalculator(const string& file, const string& username);
    void loadPortfolioDataFromFile(const string& file);
    void calculateEarnings(const string& file, const string& username);
    void generateReceipt(const string& username);
};

#endif // INVESTMENT_CALCULATOR_H