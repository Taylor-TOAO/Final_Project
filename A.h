//A.h
#ifndef STOCK_INVESTMENT_CALCULATOR_H
#define STOCK_INVESTMENT_CALCULATOR_H
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

class StockInvestmentCalculator {

private:
    double shares, price, comm, annreturn, amount, acomm, totalA, total;

public:
    StockInvestmentCalculator();
    void calculate10yearEarnings(const string& username);
};

#endif // STOCK_INVESTMENT_CALCULATOR_H