#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

/*  Name: Emanuel Dobra
    Section: 101
    Description: Creates a Sales Analysis Report
    that now takes in multiple salesman. Now also
    includes input validation and finding the
    most expensive sale.*/

int main() {
    const int SIZE = 6;
    int ctr;
    string salesName[SIZE];
    int salesAmount[SIZE];
    int salesTotal = 0, salesAvrg = 0, topSellerIndex = 0, topSellerSales = 0, sellersEntered = 0;

    ofstream fout("sales.data");

    if (!fout.is_open()) {
        cout << "error opening file";
        system("pause");
        exit(-1);
    }

    for (ctr = 0; ctr < SIZE; ctr++) {
        cout << "What is the sales person's name? Or press ctrl^z to stop ";
        getline(cin, salesName[ctr]);
        if (cin.eof()) {
            break;
        }
        sellersEntered++;
        cout << "How many sales did they make?";
        cin >> salesAmount[ctr]; // populate this element of the array
        // Validate input
        while (salesAmount[ctr] < 0 || salesAmount[ctr] > 100 || cin.fail()) {
            cin.clear();
            cin.ignore(80, '\n');
            cout << "Incorrect input, please enter a number between 0 and 100";
            cin >> salesAmount[ctr];
        }
        cin.ignore(80, '\n'); // clear buffer for correct input
        // Accumulate sales amount
        salesTotal += salesAmount[ctr];
    }
    // Calculate avrg sales amount
    if (ctr > 0)
        salesAvrg = salesTotal / (ctr);
 

    fout << right << setw(35) << "Sales Analysis Report" << endl;
    fout << left << setw(15) << "Sales person";
    fout << right << setw(35) << "Sales Amount" << endl;
    if (sellersEntered > 0) {
        for (ctr = 0; ctr < sellersEntered; ctr++) {
            fout << left << setw(35) << salesName[ctr];
            fout << right << setw(5) << salesAmount[ctr] << endl;
            // Check if sales are below average
            if (salesAmount[ctr] < salesAvrg) 
                fout << "*** below average ***" << endl;
            // Check for top seller
            if (salesAmount[ctr] > topSellerSales) {
                topSellerIndex = ctr;
                topSellerSales = salesAmount[ctr];
            }
        }
    
        fout << left << setw(15) << "Highest Sales Salesperson: "
            << right << setw(15) << salesName[topSellerIndex] << endl;
    }
    system("type sales.data");
    system("pause");
}
/* Output
What is the sales person's name? Or press ctrl^z to stop Gavin
How many sales did they make?40
What is the sales person's name? Or press ctrl^z to stop Sorin
How many sales did they make?43
What is the sales person's name? Or press ctrl^z to stop Lext
How many sales did they make?37
What is the sales person's name? Or press ctrl^z to stop Farron
How many sales did they make?41
What is the sales person's name? Or press ctrl^z to stop Dort
How many sales did they make?39
What is the sales person's name? Or press ctrl^z to stop ^Z
              Sales Analysis Report
Sales person                          Sales Amount
Gavin                                 40
Sorin                                 43
Lext                                  37
*** below average ***
Farron                                41
Dort                                  39
*** below average ***
Highest Sales Salesperson:           Sorin
Press any key to continue . . .
*/