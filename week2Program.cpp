// Single-Match Player Tracker (Week 2)

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    // Banner
    cout << "==============================\n";
    cout << " Single-Match Player Tracker\n";
    cout << "==============================\n\n";

    // User input
    string player;
    int goals = 0;
    int assists = 0;
    double minutesPlayed = 0.0;

    cout << "Enter player's full name: ";
    getline(cin, player);

    cout << "Goals scored (this match): ";
    cin >> goals;

    if (goals < 0) // Check for valid input
    {
        cout << "Invalid number of goals.\n";
        return 0;
    }


    cout << "Assists made (this match): ";
    cin >> assists;


    if (assists < 0)
    {
        cout << "Invalid number of assists.\n";
        return 0;
    }


    cout << "Minutes played (this match): ";
    cin >> minutesPlayed;


    if (minutesPlayed <= 0)
    {
        cout << "Invalid minutes played.\n";
        return 0;
    }


    // Calculations
    double gaPer90 = goals + assists;
    double impact = gaPer90 / (minutesPlayed / 90.0); // G+A per 90 min

    // Display summary
    cout << fixed << showpoint << setprecision(2);
    cout << "\n------ MATCH SUMMARY ------\n";
    cout << left << setw(15) << "Player:" << right << setw(20) << player << "\n";
    cout << left << setw(15) << "Goals:" << right << setw(20) << goals << "\n";
    cout << left << setw(15) << "Assists:" << right << setw(20) << assists << "\n";
    cout << left << setw(15) << "Minutes:" << right << setw(20) << minutesPlayed << "\n";
    cout << left << setw(15) << "G+A per 90:" << right << setw(20) << gaPer90 << "\n";
    cout << left << setw(15) << "Impact:" << right << setw(20) << impact << "\n";
    cout << "-----------------------------\n";

    // Save report to the file "report.txt"
    ofstream outData;
    outData.open("report.txt");   // open file

    if (outData)
    {
        outData << fixed << showpoint << setprecision(2);
        outData << "PLAYER MATCH REPORT\n";
        outData << "-----------------------------\n";
        outData << left << setw(15) << "Player:" << right << setw(20) << player << "\n";
        outData << left << setw(15) << "Goals:" << right << setw(20) << goals << "\n";
        outData << left << setw(15) << "Assists:" << right << setw(20) << assists << "\n";
        outData << left << setw(15) << "Minutes:" << right << setw(20) << minutesPlayed << "\n";
        outData << left << setw(15) << "Impact:" << right << setw(20) << impact << "\n";
        outData << left << setw(15) << "G+A per 90:" << right << setw(20) << gaPer90 << "\n";
        outData << "-----------------------------\n";

        outData.close();          // close file
        cout << "\nReport saved to report.txt\n";
    }
    else
    {
        cout << "\nError: could not open file.\n";
    }

    return 0;
}


