#include "B.h"

InvestmentCalculator::InvestmentCalculator(const string& file, const string& username)//Constructor
    : shares(0), price(0), comm(0), annreturn(0), years(0), amount(0), acomm(0), total(0) {}//Initializer list
    //void loadPortfolioDataFromFile();
    //void calculateEarnings();
    //void generateReceipt(string username);



void InvestmentCalculator::loadPortfolioDataFromFile(const string& file) {
    ifstream infile(file);
    //Ensure input file is saved with the correct name (in this example: sample.txt) and is in the correct location.
    //sample.txt file should only contain doubles of number of shares, price of each share, commision fee as a percentage
    //the expected annual return rate as a percentage, and the total number of years to forecast the investment
    if (!infile) {
        cout << "File failed to open" << endl;
    }
    else {
        infile >> shares >> price >> comm >> annreturn >> years;
        infile.close();
    }
}

void InvestmentCalculator::calculateEarnings(const string& file, const string& username) {
    amount = shares * price;
    cout << "The amount paid for the stock alone (without broker commission): $" << amount << ".\n";

    comm = amount * (comm / 100);
    cout << "The amount paid for commission: $" << comm << ".\n";

    totalA = amount + comm;
    cout << "The total amount paid (the payment for stock plus the commission): $" << totalA << ".\n";

    total = amount * pow(1 + (annreturn / 100), years);
    cout << "After " << years << " years your shares will be worth: $" << total << ".\n\n";
}

void InvestmentCalculator::generateReceipt(const string& username) {
    char receipt_response = 0;

    while (receipt_response != 'n' && receipt_response != 'N') {
        cout << "Would you like a receipt? Y/N ";
        cin >> receipt_response;
        cout << endl;

        if (receipt_response == 'Y' || receipt_response == 'y') {
            ofstream outfile("receipt.txt");

            if (!outfile) {
                cout << "I'm sorry but your receipt failed to generate. Please check your file path" << endl;
            }
            else {
                outfile << "Username: " << username << endl;
                outfile << "-------------------------------------------" << endl;

                outfile << setprecision(2) << fixed;
                outfile << "Total stock:" << setw(21) << "$" << setw(10) << right << amount << endl;
                outfile << "Commission:" << setw(22) << "$" << setw(10) << right << comm << endl;
                outfile << "Total amount:" << setw(20) << "$" << setw(10) << right << totalA << endl;

                outfile << setprecision(0) << fixed;
                outfile << "Net worth in " << years << " years:" << setw(11) << "$";
                outfile << setprecision(2) << fixed;
                outfile << setw(10) << total << endl;
            }

            outfile.close();
            cout << "Your receipt has been generated under receipt.txt." << endl << endl;

            break;
        }
    }
}