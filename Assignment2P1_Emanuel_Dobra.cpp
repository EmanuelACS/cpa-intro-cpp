#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

/*****************************************************************
Name: Emanuel Dobra                          Assignment #2 Phase 1
Program: Handles multiple guest charges at a hotel. Phase 1 will
 work for one guest only.
*****************************************************************/
int main()
{
    // Variable declarations with defaults
    string guestName = "Not set";
    char roomType = 'G';
    int numOfDays = 1;
    double roomCharge = 125.00;

    // Open output file
    ofstream fout("charges.dat");
    // Set conditions
    fout << setprecision(2) << fixed;
    // Output title to file
    fout << left << setw(15) << ""
        << right << setw(25) << "CPA Resort Hotel Room Charge" << endl;
    fout << left << setw(20) << "Guest Name"
        << left << setw(15) << "Room Type"
        << left << setw(10) << "# Days"
        << right << setw(15) << "Room Charge" << endl;

    // User Input
    cout << "What is your name: ";
    getline(cin, guestName);
    cout << "What room type would you like: ";
    cin >> roomType;
    cout << "How many days would you like to stay: ";
    cin >> numOfDays;

    // Calculate charge
    roomCharge = numOfDays * 125.00;

    // Output info to file
    fout << left << setw(20) << guestName
        << left << setw(15) << roomType
        << left << setw(10) << numOfDays
        << right << setw(15) << roomCharge << endl;

    system("type charges.dat");
    system("pause");
}

/* Output
What is your name: Emanuel Dobra
What room type would you like: L
How many days would you like to stay: 17
               CPA Resort Hotel Room Charge
Guest Name          Room Type      # Days        Room Charge
Emanuel Dobra       L              17                2125.00
Press any key to continue . . .
*/