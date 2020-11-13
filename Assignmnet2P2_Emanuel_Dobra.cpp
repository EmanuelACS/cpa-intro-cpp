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
    double roomRate = 0;
    string roomName = "Not set";

    // Open output file
    ofstream fout("charges.dat");
    // Ensure file opened successfully
    if (!fout.is_open())
    {
        cout << "error opening file";
        system("pause");
        exit(-1);
    }
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
    cout << "What room type would you like (G, P or L): ";
    cin >> roomType;
    cout << "How many days would you like to stay: ";
    cin >> numOfDays;

    // Determine room name and rate
    if (roomType == 'G') {
        roomRate = 125.00;
        roomName = "Garden View";
    }
    else if (roomType == 'P') {
        roomRate = 145.00;
        roomName = "Pool View";
    }
    else if (roomType == 'L') {
        roomRate = 180.00;
        roomName = "Lake View";
    }
    else {
        cout << "Invalid Room Type Input" << endl;
        cout << "Program has been terminated" << endl; 
        system("pause");
        exit(-1);
    }

    // Calculate charge
    roomCharge = numOfDays * roomCharge;

    // Output info to file
    fout << left << setw(20) << guestName
        << left << setw(15) << roomName
        << left << setw(10) << numOfDays
        << right << setw(15) << roomCharge << endl;

    system("type charges.dat");
    system("pause");
}
/* Output
What is your name: Emanuel Dobra
What room type would you like (G, P or L): P
How many days would you like to stay: 17
               CPA Resort Hotel Room Charge
Guest Name          Room Type      # Days        Room Charge
Emanuel Dobra       Pool View      17                2125.00
Press any key to continue . . .
*/