//The following README file contains instructions for Taylor Stokes' CMakeFinalProject for AERSP 424:User Investment Portfolio

//The final poroject was develeped with OOP in mind. Thus, at the top of the code, one can see the included header files, which for 
//A.h-D.h, include classes and member function classes which are called throughout the main file.
//NOTE:CMakeFinalProject.cpp is the main file

//To get started ensure that you have the following input files stored in the correct location for the compiler so that they can be accessed by the project when called:
//UN.txt
//PW.txt
//sample.txt
//collegeinput.text
//OptD.txt

//Each of the above listed .txt files will be explained in detail throughout this README.

//When starting up the code, there will be a login system to verify a username and password. The main file will automatically open the input files UN.txt and PW.txt 
//to store data into their respective vectors. The files I have provided already have listed exalmples however, if you wish to run your own, ensure that for each .txt file
//that you input your prefence and then input the next preference of a newline to ensure the information is inputted into the vector correctly.
//Current UN.txt file includes:
//abc
//def
//ghi
//Current PW.txt file includes:
//123
//456
//789
//Current login system limits the the inputs to 10, but you can adjust this to your preference or even indefinitely if you so choose.

//The main code then calls the UNsearch function to verify that the UN provided by the user indeed is correct
//The UNsearch is then followed by the PWsearch function which not only verifies that the password provided by the user is correct, but also that the stored
//location of the password aligns with that of the username to properly login to the system.
//If the UN does not checkout or the password is either wrong or does not match the UN, the system will keep looping, allowing the chance for the user to input the correct information

//Once login is successful, the user will be brought to the main system of the software where they can then choose from Options A-E. The system prompts the user
//for input to access their desired investment calcuation. If input is incorrect, the user will be prompted to try again or they can exit the system.

//Option A: 10 Year Investment Projection
//The main function calls outside functions within A.cpp. Within A.cpp is the class StockInvestmentCalculator and respective member functions. A.cpp prompts the user with 
//needed information and then generates and expected value of the stock after 10 years based off provided values from the user.
//The user is then asked if they would like to return to the main menu, if yes, the loop continues, if no the software exits.

//Option B: Retirement Planning
//The main function calls outside functions within B.cpp. Within B.cpp is the class InvestmentCalculator and the respective member functions.
//First the following information is read from the infile "sample.txt" and is stored within local variables for a later calculation:
//Number of shares to be purchased
//The price of each share at the time of purchase
//The commission fee of the broker expressed as a percentage
//The total number of years of the investment

//The earnings are then calculated and then cout to the user for verification. The user is then prompted if they would like a receipt. If the user elects to do so, the
//calculations will be sent to the outfile "receipt.txt".
//The user is then asked if they would like to return to the main menu, if yes, the loop continues, if no the software exits.

//Option C: Monthly Mortgage Calculator
//The main function calls outside functions within C.cpp. Within C.cpp is the class MortgageCalculator and the respective member functions.
//First the following information is read from the infile "mortgage.txt" and is stored within local variables for a later calculation:
//Principle amount of the loan
//The fixed interest rate of the loan
//The loan term in years

//The member function class CalculateMortgage() then calculates the monthly mortgage payment
//The results are then sent/generated to an outfile "out.txt" for the user.
//The user is then asked if they would like to return to the main menu, if yes, the loop continues, if no the software exits.

//Option D: Collge Fund Investment Calculator
//The main function calls outside functions within D.cpp. Within D.cpp is the class MortgageCalculator and the respective member functions.
//The first member function getInput() receives user input for the principle amount (that is, the initial investment) and an expected interest rate of the investment.
//The second member function readDataFromFile then takes monthly investments and stores them within the 'months' vector. The respective infile is OptD.txt and can contain 
//as many monthly investments as the user desires. The monthly investments are a dollar amount.
//The third member function calculateCollegeFuncd() then calculates the investment based off the user input and monthly investments.
//First, the total number of months is calculated and then adjusted to round up to the total number of years invested. This is for ease of calculation but does not
//affect the total amount invested across all months.
//There is then a for loop with a nested for loop. The first for loop runs through the total number of years invested and then the second for loop sums up all of the months
//within each respective year and sums them up in a new vector, 'years'. Additional comments are embedded within the code.
//The last loop then runs through each year to apply the expected interest rate. The first year adds the initial investment (principle) to the first 12 month sum and the 
//multiplies it by the interest rate.
//Each subsequent year then adds the previos year to that years calculated sum and multiplies it by the interest rate.
//Finally, the calculations are genereated under outfile "College_fund.txt" calculated the total networth across the total amount of years which was determined 
//by the amount of months invested read from the OptD.txt file earlier.
//The user is then asked if they would like to return to the main menu, if yes, the loop continues, if no the software exits.

//The code will keep looping until the user either chooses E || e at the main menu or selects N || n when asked if they would like to return to the main menu
//after executing one of the options. 

//Tp reitereate, to ensure that the software runs correctly, ensure the proper files are stored in the correct location so the compiler can access them and that all
//appropriate data is stored correctly within the .txt files. Use the included files as reference first and then adjust to your desire to calculate your own investments!
