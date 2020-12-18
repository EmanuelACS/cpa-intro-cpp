#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

/*  Name: Emanuel Dobra
    Section: 101
    Description: Creates a Sales Analysis Report
    that takes in multiple salesman and shows the average,
    who had salse below it, and the highest seller.*/

int main() {
    const int SIZE = 6;
    int ctr;
    string salesName[SIZE];
    double salesAmount[SIZE];
    double salesTotal = 0, salesAvrg = 0, topSellerSales = 0;
    int topSellerIndex = 0, sellersEntered = 0;

    ofstream fout("sales.data");

    if (!fout.is_open()) {
        cout << "error opening file";
        system("pause");
        exit(-1);
    }

    for (ctr = 0; ctr < SIZE; ctr++) {
        cout << "What is the sales person's name? Or press ctrl^z to stop: ";

        getline(cin, salesName[ctr]);
        if (cin.eof()) {
            break;
        }
        while (cin.fail() || salesName[ctr].empty()) {
            cin.clear();
            cin.ignore(80, '\n');
            cout << "Incorrect input, please enter the sales' person name or ctrl^z to stop: ";
            getline(cin, salesName[ctr]);
            if (cin.eof()) {
                break;
            }
        }
        if (cin.eof()) {
            break;
        }
        sellersEntered++;
        cout << "How many sales did they make? ";
        cin >> salesAmount[ctr]; // populate this element of the array
        // Validate input
        while (salesAmount[ctr] < 0 || salesAmount[ctr] > 100 || cin.fail()) {
            cin.clear();
            cin.ignore(80, '\n');
            cout << "Incorrect input, please enter a number between 0 and 100: ";
            cin >> salesAmount[ctr];
        }
        cin.ignore(80, '\n'); // clear buffer for correct input
        // Accumulate sales amount
        salesTotal += salesAmount[ctr];
    }
    // Calculate avrg sales amount
    if (ctr > 0)
        salesAvrg = salesTotal / (ctr);

    fout << fixed << setprecision(2);
    fout << right << setw(35) << "Sales Analysis Report" << endl;
    fout << left << setw(15) << "Sales person";
    fout << right << setw(35) << "Sales Amount" << endl;
    if (sellersEntered > 0) {
        for (ctr = 0; ctr < sellersEntered; ctr++) {
            fout << left << setw(35) << salesName[ctr];
            fout << right << setw(8) << salesAmount[ctr];
            // Check if sales are below average
            if (salesAmount[ctr] < salesAvrg)
                fout << " *** below average ***";
            fout << endl;
            // Check for top seller
            if (salesAmount[ctr] > topSellerSales) {
                topSellerIndex = ctr;
                topSellerSales = salesAmount[ctr];
            }
        }
        fout << endl << left << setw(35) << "Average Sales Amount"
            << right << setw(8) << salesAvrg << endl;
        fout << salesName[topSellerIndex] << " sold the most! " << endl;
    }
    system("type sales.data");
    system("pause");
}
/* Output
What is the sales person's name? Or press ctrl^z to stop: P1
How many sales did they make? 42
What is the sales person's name? Or press ctrl^z to stop: P2
How many sales did they make? 43
What is the sales person's name? Or press ctrl^z to stop: P3
How many sales did they make? 44
What is the sales person's name? Or press ctrl^z to stop: P5
How many sales did they make? 921
Incorrect input, please enter a number between 0 and 100: 231
Incorrect input, please enter a number between 0 and 100: 45
What is the sales person's name? Or press ctrl^z to stop: P4
How many sales did they make? 41
What is the sales person's name? Or press ctrl^z to stop: ^Z
              Sales Analysis Report
Sales person                          Sales Amount
P1                                    42.00 *** below average ***
P2                                    43.00
P3                                    44.00
P5                                    45.00
P4                                    41.00 *** below average ***

Average Sales Amount                  43.00
P5 sold the most!
Press any key to continue . . .
*/