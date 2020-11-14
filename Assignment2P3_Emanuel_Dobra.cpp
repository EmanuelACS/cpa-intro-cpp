#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

/*****************************************************************
Name: Emanuel Dobra                          Assignment #2 Phase 3
Program: Handles multiple guest  charges at a  hotel. Phase 1 will
 work for one guest  only. Phase 2 will distinguish  between  room
 types and output price  and details accordingly. Phase 3 will let
 multiple guests  be registered  until user decides to stop input.
*****************************************************************/
int main()
{
    // Variable declarations
    string guestName, roomName;
    char roomType;
    int numOfDays;
    double roomCharge, roomRate;

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
    cout << "Input the first guest's name (or ^Z to quit): ";

    /* I tried using the following:
    * while (!cin.eof()) { }
    * However, it would always cause an extra loop which would
    *  add another blank guest with the last used roomType, 
    *  roomRate and numOfDays input. The only way I found of 
    *  fixing this without adding more arguments to the while 
    *  loop is by using the getline as the while loop argument
    *  instead of !cin.eof, which will stop the program before
    *  it loops an extra time. I hope this is okay.
    * Example of what output used to look like:
    * Guest Name          Room Type      # Days        Room Charge
    * Sahim               Garden View    24                3000.00
    * Sarah               Pool View      12                1740.00
    * Corinth             Lake View      4                  720.00
    * Sonder              Pool View      7                 1015.00
    *                     Pool View      7                 1015.00 <-- This is the line I wanted to get rid of
    */
    while (getline(cin, guestName)) {
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
        roomCharge = numOfDays * roomRate;

        // Output info to file
        fout << left << setw(20) << guestName
            << left << setw(15) << roomName
            << left << setw(10) << numOfDays
            << right << setw(15) << roomCharge << endl;
        cout << "Please input the next guest's name (or ^Z to quit): ";
        cin.ignore(80, '\n');
    }

    system("type charges.dat");
    system("pause");
}
/* Output
Input the first guest's name (or ^Z to quit): Sahim
What room type would you like (G, P or L): G
How many days would you like to stay: 24
Please input the next guest's name (or ^Z to quit): Sarah
What room type would you like (G, P or L): P
How many days would you like to stay: 12
Please input the next guest's name (or ^Z to quit): Corinth
What room type would you like (G, P or L): L
How many days would you like to stay: 4
Please input the next guest's name (or ^Z to quit): Sonder
What room type would you like (G, P or L): P
How many days would you like to stay: 7
Please input the next guest's name (or ^Z to quit): ^Z
               CPA Resort Hotel Room Charge
Guest Name          Room Type      # Days        Room Charge
Sahim               Garden View    24                3000.00
Sarah               Pool View      12                1740.00
Corinth             Lake View      4                  720.00
Sonder              Pool View      7                 1015.00
Press any key to continue . . .
*/