#include "D.h"

CollegeFundCalculator::CollegeFundCalculator() //Constructor
    : D_Principle(0), D_IR(0), networth(0), total(0), months(), years() {}//Initilizer list

    void CollegeFundCalculator::getInput() {
        //Principle is the intial investment amount
        //Interest rate is the expected annual interest rate (typically 7 percent) expressed as a percentage
        //So for 7%, just type 7
        cout << "Please enter the following:" << endl;
        cout << "Initial Investment: ";
        cin >> D_Principle;
        cout << "Expected interest rate: ";
        cin >> D_IR;
    }

    void CollegeFundCalculator::readDataFromFile(const string& file) {
        ifstream optD_infile(file);
        //Ensure input file is saved with the correct name (in this example: collegeinput.txt) and is in the correct location.
        //The input should be the monthly savings expressed as a double. The amount of months is up to the user.
        if (optD_infile) {
            double count;
            for (int i = 0; optD_infile >> count; i++) {
                months.push_back(count);
                //cout << count << endl;
                total++;
            }
            optD_infile.close();
        }
        else {
            cout << "File failed to open.";
        }
    }

    void CollegeFundCalculator::calculateCollegeFund() {
        int counter = total;
        double no_months = total;
        //Adjusts the counter to make the total number of months divisible by 12 to account for the number of years invested.
        //This does not affect the total investment.
        while (!(counter % 12 == 0)) {
            total++;
            counter = total;
        }

        int sum;
        //first for loop runs through the total number of years thanks to the total now divisible by 12
        for (int i = 0; i < (total / 12); i++) {
            sum = 0;
            //Nested for loop runs throuh each month of the year and sums them up and stores them in a new vector 'years'.
            //Here we can see that the total is not affected because, lets say that for the last year, there are only 4 months of
            //investment, well for the remainder of the monthsof that year it will add zeros.
            for (int m = i * 12; m < (i + 1) * 12; m++) {
                sum += months[m];
                years.push_back(sum);
            }
            
        }

        int loop_counter = 0;
        double networth = D_Principle;
        for (int l = 0; l < years.size(); l++) {
            if (l == 0)
            {
                //Done to ensure that the principle amount (i.e. the initial investement) is only
                //added one time.
                networth = ((D_Principle + years[l]) * (1 + (D_IR / 100)));
                //cout << networth << endl;//checkpoint in code
                loop_counter++;
            }
            else
            {
                networth = ((networth + years[l]) * (1 + (D_IR / 100)));
                //cout << networth << endl;//checkpoint in code
                loop_counter++;
            }
        }
        //pointer
        this->networth = networth;
    }

    

    void CollegeFundCalculator::generateOutputToFile(const string& username) {
        ofstream college_out("College_fund.txt");

        if (!college_out) {
            cout << "I'm sorry but your college fund failed to generate. Please check your file path";
        }
        else {
            college_out << "Hello: " << username << endl;
            college_out << "-------------------------------------------" << endl; // Aesthetic separation line

            college_out << setprecision(2) << fixed;
            college_out << "Principle:" << setw(30) << D_Principle << endl;
            college_out << "Interest Rate:" << setw(26) << D_IR << endl;
            college_out << "Saving Period (in month):" << setw(15) << total << endl;
            college_out << "Net worth after " << (total / 12) << " years:" << setw(16) << networth << endl;
        }
        college_out.close();
        cout << "\nYour college fund net worth has been generated under College_fund.txt.\n\n";
        
    }

