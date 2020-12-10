#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

/*  Name: Emanuel Dobra
    Section: 101
    Description: Creates a Sales Analysis Report */

int main() {
    string salesName;
    int salesAmount;

    ofstream fout("sales.data");

    if (!fout.is_open())
    {
        cout << "error opening file";
        system("pause");
        exit(-1);
    }
    //fout << fixed << setprecision(2);
    fout << right << setw(35) << "Sales Analysis Report" << endl;
    fout << left << setw(15) << "Sales person";
    fout << right << setw(35) << "Sales Amount" << endl;
    cout << "What is the sales person's name?";
    getline(cin, salesName);
    cout << "How many sales did they make?";
    cin >> salesAmount;
    fout << left << setw(35) << salesName;
    fout << right << setw(5) << salesAmount << endl;
    system("type sales.data");
    system("pause");
}
/* Output
What is the sales person's name?Marvin Carol
How many sales did they make?25
              Sales Analysis Report
Sales person                          Sales Amount
Marvin Carol                          25
Press any key to continue . . .
*/