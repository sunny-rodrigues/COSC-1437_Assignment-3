// Programming Assignment 3
// Programming Fundamentals II (COSC 1437)
// Author: Sunny Rodrigues
// Description: Reads employee records from a file, writes a formatted
//              payroll report, then demonstrates stream-inspection
//              functions and input-failure handling.
 
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <limits>
 
using namespace std;

int main()
{
    ifstream inFile;
    ofstream outFile;

    inFile.open("payrollData.txt");
    outFile.open("payrollReport.txt");

    if (!inFile)
    {
        cout << "Error: Could not open payrollData.txt" << endl;
        return 1;
    }

    string firstName, lastName, department;
    double grossSalary, bonusPercent, taxPercent;
    double distance, travelTime;
    double paycheck, averageSpeed;
 
    outFile << fixed << showpoint << setprecision(2);

        while (inFile >> firstName)
        {
        inFile >> lastName >> department;
        inFile >> grossSalary >> bonusPercent >> taxPercent;
        inFile >> distance >> travelTime;
        
        paycheck = grossSalary
                 + (grossSalary * bonusPercent / 100.0)
                 - (grossSalary * taxPercent / 100.0);
        
        averageSpeed = distance / travelTime;

        outFile << "Name: " << firstName << " " << lastName
                << ", Department: " << department << endl;
    
        outFile << "Monthly Gross Salary: $"
                << setw(10) << grossSalary
                << ", Bonus: " << bonusPercent
                << "%, Taxes: " << taxPercent << "%" << endl;

        outFile << "Paycheck: $" << paycheck << endl;

        outFile << "Distance Traveled: " << distance
                << " miles, Travel Time: "
                << travelTime << " hours" << endl;

        outFile << "Average Speed: " << averageSpeed
                << " miles per hour" << endl;

        outFile << endl;
        }

    inFile.close();
    outFile.close();

    // ---------- PART 2: STREAM INSPECTOR ----------

        cout << "\nEnter a line of text: ";

    char firstChar = cin.peek();

    if (isdigit(firstChar))
    {
        cout << "The first character is a digit." << endl;
    }
    else if (isalpha(firstChar))
    {
        cout << "The first character is a letter." << endl;
    }
    else
    {
        cout << "The first character is neither a digit nor a letter."
             << endl;
    }

    string line;
    getline(cin, line);

    cout << "You entered: " << line << endl;

    int number;
    string description;

    cout << "\nEnter an integer: ";
    cin >> number;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter a description: ";
    getline(cin, description);

    cout << "Integer entered: " << number << endl;
    cout << "Description entered: " << description << endl;

    double value;
    cout << "\nEnter a number: ";
    cin >> value;

    if (cin.fail())
    {
        cout << "Invalid input. You did not enter a valid number."
             << endl;

        cin.clear();

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    else
    {
        cout << "Valid number entered: " << value << endl;
    }

    return 0;
}
