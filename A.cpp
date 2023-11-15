#include "A.h"

StockInvestmentCalculator::StockInvestmentCalculator()://Constructor
    shares(0), price(0), comm(0), annreturn(0), amount(0), acomm(0), totalA(0), total(0) {}//Initializer list


    void StockInvestmentCalculator::calculate10yearEarnings(const string& username) 
    {
        cout << "Greetings " << username << ", today we will calculate your 10 year earnings through a stock investment.\n\n";
        cout << "NOTE: Limit your input to real numbers and do not include any special characters (%, $, etc).\n\n";

        cout << "How many shares would you like to purchase? ";
        cin >> shares;

        cout << "What is the price per share? ";
        cin >> price;

        cout << "What is the percent commission for the broker for each transaction? ";
        cin >> comm;

        cout << "Lastly, what is the average annual return, expressed as a percentage? ";
        cin >> annreturn;
        cout << endl;

        amount = shares * price;
        cout << "The amount paid for the stock alone (without broker commission): $" << amount << ".\n";

        comm = amount * (comm / 100);
        cout << "The amount paid for commission: $" << comm << ".\n";

        totalA = amount + comm;
        cout << "The total amount paid (the payment for stock plus the commission): $" << totalA << ".\n";

        total = amount * pow(1 + (annreturn / 100), 10);
        cout << "After TEN years, your shares will be worth: $" << total << "." << endl << endl;
    }
