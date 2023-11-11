// CMakeFinalProject.cpp : Defines the entry point for the application.

#include "CMakeFinalProject.h"
#include "UNsearch.h"
#include "PWsearch.h"
#include "A.h"
#include "B.h"
#include "C.h"
#include "D.h"
#include <iostream>
#include <vector>

int main()
{ 
    //Login system
    const int size = 10;
    string user_name[size];
    //Open external file to input username's into a vector
    ifstream UNinfile("UN.txt");
    
    if (!UNinfile)
        cout << "File failed to open." << endl;
    else
    {
        for (int i = 0; i < 10; i++)
        {
            UNinfile >> user_name[i];
        }
    }
    UNinfile.close();
    string pass_word[size];
    //Open external file to input password's into a vector
    ifstream PWinfile("PW.txt");

    if (!PWinfile)
        cout << "File failed to open." << endl;
    else
    {
        for (int i = 0; i < size; i++)
        {
            PWinfile >> pass_word[i];
        }

    }
    PWinfile.close();

    string UN, PW;
    int result;
    do
    {
        //Take user input to for username, call external file searchList to verify that the input is indeed a username
        cout << "Enter username: ";
        cin >> UN;
        result = searchList(user_name, size, UN);

        if (result == -1)
            cout << "\nInvalid username, please try again." << endl << endl;
    } 
    while (result == -1);
    {
        bool result2;
        do
        {
            //Take in user input for password. searchPWList then verifies not only the password but that the location/position
            //of the password in the vector mathces that of the username. 
            cout << "\nPlease enter password: ";
            cin >> PW;
            cout << endl;
            result2 = searchPWList(pass_word, size, PW, result);

            if (result2 == true)
                cout << "Invalid password, please try again\n";
        } 
        while (result2);
        {
            char answer = 0;
            while (!(answer == 'E' || answer == 'e'))
            {
                //Generate Options A-E for the user
                cout << endl << "Hello " << UN << ", listed below are our offered services: \n\n";
                cout << "A: 10 Year Investment Projection\n" << "B: Retirement Planning\n" << "C: Monthly Mortgage Calculator\n" << "D: College Fund\n" << "E: Exit\n" << endl;

                cout << "Please select a service: ";
                cin >> answer;

                cout << endl;                
                if (answer == 'A' || answer == 'a')
                {
                    StockInvestmentCalculator calculator;
                    calculator.calculate10yearEarnings(UN);
                }
                else if (answer == 'B' || answer == 'b')
                {
                    InvestmentCalculator calculator("sample.txt", UN);
                    calculator.loadPortfolioDataFromFile("sample.txt");
                    calculator.calculateEarnings("sample.txt", UN);
                    calculator.generateReceipt(UN);

                }
                else if (answer == 'C' || answer == 'c')
                {
                    MortgageCalculator calculator("mortgage.txt", UN);
                    calculator.loadInputDataFromFile("mortgage.txt");
                    calculator.CalculateMortgage();
                    calculator.generateOutput(UN);
                }
                else if (answer == 'D' || answer == 'd')
                {
                    CollegeFundCalculator calculator;
                    calculator.getInput();
                    calculator.readDataFromFile("collegeinput.txt");
                    calculator.calculateCollegeFund();
                    calculator.generateOutputToFile(UN);
                }
                else if (answer == 'E' || answer == 'e') {
                    cout << "Have a nice day!";
                    break;
                }
                else
                {
                    cout << "Invalid selection. Please try again." << endl;
                    continue;
                }
                char response;
                do
                {
                    cout << "Would you like to go back to the main menu? (Y/N) ";
                    cin >> response;

                    if (response == 'n' || response == 'N')
                        break;//breaks do/while loop

                    else if (response == 'y' || response == 'Y')//skips over else statement
                    {}

                    else //catches all response not 'y', 'Y', 'n' or 'N' and re-executes loop 
                    {
                        cout << "\nInvalid input, please try again." << endl << endl;
                        continue;//sends user back to do/while loop to try again
                    }
                }
                while (!(response == 'Y' || response == 'y'));
                {
                    if (response == 'y' || response == 'Y')
                        continue;//sends user back to main menu

                    else if (response == 'n' || response == 'N')
                    {
                        cout << "\nHave a nice day!";
                        break;//terminates program
                    }
                }        
            }
        }
    }
    return 0;
}