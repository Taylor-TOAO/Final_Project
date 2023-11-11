#include "C.h"

MortgageCalculator::MortgageCalculator(const string& file, const string& username)
    : principle(0), interest_rate(0), loan_term(0), monthly_payment(0) {}


void MortgageCalculator::loadInputDataFromFile(const string& file) {
    ifstream load_input(file);
    //Ensure input file is saved with the correct name (in this example: mortgage.txt) and is in the correct location.
    //mortgage.txt file should only contain doubles of the principle amount of the loan, the fixed interest rate of the loan,
    // and the total number of years the loan is for (for a home loan, it is typically either 15 or 30).
    if (!load_input) {
        cout << "File failed to open" << endl;
    }
    else {
        load_input >> principle >> interest_rate >> loan_term;
        load_input.close();
    }
}

void MortgageCalculator::CalculateMortgage() {
    double IR, LT;
    IR = (interest_rate / 12) / 100;
    LT = loan_term * 12;
    monthly_payment = principle * ((IR * pow((1 + IR), LT)) / (pow((1 + IR), LT) - 1));
}


void MortgageCalculator::generateOutput(const string& username) {
    ofstream out_mort("out.txt");
    if (!out_mort) {
        cout << "I'm sorry, but the mortgage calculator failed to output to out.txt. Please check your file path and try again." << std::endl;
    }
    else {
        out_mort << "Hello " << username << ":" << endl;
        out_mort << "----------------------------------------------" << endl;
        out_mort << setprecision(2) << fixed;
        out_mort << "Principle:" << setw(36) << principle << endl;
        out_mort << "Interest Rate:" << setw(32) << interest_rate << endl;
        out_mort << "Loan term (in years):" << setw(25) << loan_term << endl;
        out_mort << "Monthly Mortgage Payment:" << setw(21) << monthly_payment << endl;
    }
    
    out_mort.close();
    cout << "Your mortgage calculations have been generated under out.txt." << endl;
}