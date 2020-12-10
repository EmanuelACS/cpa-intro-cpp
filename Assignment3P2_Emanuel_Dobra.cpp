#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

/*  Name: Emanuel Dobra
    Section: 101
    Description: Creates a Sales Analysis Report
    that now takes in multiple salesman. */

int main() {
    const int SIZE = 4;
    int ctr;
    string salesName[SIZE];
    int salesAmount[SIZE];

    ofstream fout("sales.data");

    if (!fout.is_open()) {
        cout << "error opening file";
        system("pause");
        exit(-1);
    }

    for (ctr = 0; ctr < SIZE; ctr++) {
        cout << "What is the sales person's name? Or press ctrl^z to stop";
        getline(cin, salesName[ctr]);
        if (cin.eof()) {
            break;
        }
        cout << "How many sales did they make?";
        cin >> salesAmount[ctr];
        cin.ignore(80, '\n');
    }

    fout << right << setw(35) << "Sales Analysis Report" << endl;
    fout << left << setw(15) << "Sales person";
    fout << right << setw(35) << "Sales Amount" << endl;

    for (ctr = 0; ctr < SIZE; ctr++) {
        fout << left << setw(35) << salesName[ctr];
        fout << right << setw(5) << salesAmount[ctr] << endl;
    }

    system("type sales.data");
    system("pause");
}
/* Output
What is the sales person's name? Or press ctrl^z to stopEmanuel
How many sales did they make?52
What is the sales person's name? Or press ctrl^z to stopMArina
How many sales did they make?12
What is the sales person's name? Or press ctrl^z to stopCail
How many sales did they make?15
What is the sales person's name? Or press ctrl^z to stopSoro
How many sales did they make?11
              Sales Analysis Report
Sales person                          Sales Amount
Emanuel                               52
MArina                                12
Cail                                  15
Soro                                  11
Press any key to continue . . .
*/