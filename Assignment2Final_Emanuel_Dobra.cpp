#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

/*****************************************************************
Name: Emanuel Dobra                            Assignment #2 Final
Program: Handles multiple guest  charges at a  hotel. Phase 1 will
 work for one guest  only. Phase 2 will distinguish  between  room
 types and output price  and details accordingly. Phase 3 will let
 multiple guests  be registered  until user decides to stop input.
 Lastly, the final phase will make sure all inputs are valid while
 also calculating the average room cost. 
*****************************************************************/

int main()
{
    // Variable declarations
    string guestName, roomName;
    char roomType;
    int numOfDays, numOfGuests = 0; 
    double roomCharge, roomRate, averageCharge;
    double totalCharge = 0.00;

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
        << right << setw(10) << "# Days"
        << right << setw(15) << "Room Charge" << endl;

    // User Input
    cout << "Input the first guest's name (or ^Z to quit): ";

    // While not end of input
    while (getline(cin, guestName)) {
        // Ask for room type & # of days 
        cout << "What room type would you like (G, P or L): ";
        cin >> roomType;
        // Check for valid room input 
        while (toupper(roomType) != 'G' 
            && toupper(roomType) != 'P' 
            && toupper(roomType) != 'L') {
            // Clear buffer
            cin.clear();
            cin.ignore(80, '\n');
            // Ask for new input
            cout << "Error, please re-enter the value: ";
            cin >> roomType;
        }
        cout << "How many days would you like to stay: ";
        cin >> numOfDays;
        // Check for valid days input
        while (numOfDays < 1 || numOfDays > 365) {
            // Handle non-integer inputs
            if (cin.fail()) {
                cin.clear();
                cin.ignore(80, '\n');
            }
            // Ask for new value
            cout << "Error, please re-enter the value: ";
            cin >> numOfDays; 
        }

        // Determine room name and rate
        if (toupper(roomType) == 'G') {
            roomRate = 125.00;
            roomName = "Garden View";
        }
        else if (toupper(roomType) == 'P') {
            roomRate = 145.00;
            roomName = "Pool View";
        }
        else {
            roomRate = 180.00;
            roomName = "Lake View";
        }

        // Calculate charge & guests
        roomCharge = numOfDays * roomRate;
        totalCharge += roomCharge;
        numOfGuests++;

        // Output info to file
        fout << left << setw(20) << guestName
            << left << setw(15) << roomName
            << right << setw(10) << numOfDays
            << right << setw(15) << roomCharge << endl;
        cout << "Please input the next guest's name (or ^Z to quit): ";
        cin.ignore(80, '\n');
    }
    // Calculate and output average charge
    if (numOfGuests == 0)
        averageCharge = 0;
    else 
        averageCharge = totalCharge / numOfGuests;
    fout << endl << left << setw(20) << "Average Room Charge"
        << right << setw(40) << averageCharge << endl;

    cout << "====================== Printing File ======================="
        << endl;
    system("type charges.dat");
    system("pause");
}
/* Output
Input the first guest's name (or ^Z to quit): Cassandra
What room type would you like (G, P or L): G
How many days would you like to stay: 4
Please input the next guest's name (or ^Z to quit): Logan
What room type would you like (G, P or L): P
How many days would you like to stay: 3
Please input the next guest's name (or ^Z to quit): John
What room type would you like (G, P or L): L
How many days would you like to stay: 5
Please input the next guest's name (or ^Z to quit): Simon
What room type would you like (G, P or L): P
How many days would you like to stay: 8
Please input the next guest's name (or ^Z to quit): Sara
What room type would you like (G, P or L): L
How many days would you like to stay: 7
Please input the next guest's name (or ^Z to quit): ^Z
====================== Printing File =======================
               CPA Resort Hotel Room Charge
Guest Name          Room Type          # Days    Room Charge
Cassandra           Garden View             4         500.00
Logan               Pool View               3         435.00
John                Lake View               5         900.00
Simon               Pool View               8        1160.00
Sara                Lake View               7        1260.00

Average Room Charge                                   851.00
Press any key to continue . . .
*/