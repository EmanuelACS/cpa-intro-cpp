#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/*****************************************************************
Name: Emanuel Dobra                                  Assignment #1
Program: Displays to the user the receipt for their book purchases
*****************************************************************/
int main()
{
    // Variable Declarations
    string bookTitle = "Not set";
    int bookQuantity; 
    double unitPrice, subTotal, total, tax;
    const double taxRate = 0.15;

    // Output Rules
    cout << fixed << setprecision(2);

    // User Input
    /* If you use a cin >> before a getline(cin, var), 
        you want to add cin.ignore(80, '/n') before the getline()*/
    cout << "Enter the book's title: ";
    getline(cin, bookTitle);
    cout << "Enter the number of copies: " ;
    cin >> bookQuantity;
    cin.ignore(80, '\n');
    cout << "Enter the price of the book: ";
    cin >> unitPrice;

    // Processing arithmetic 
    subTotal = unitPrice * bookQuantity;
    tax = subTotal * taxRate;
    total = subTotal + tax;

    // Output
    cout << left << "\nAmazing Booksellers" << endl;
    cout << left << setw(25) << "Title" 
        << left << setw(5) << "QTY" 
        << right << setw(10) << "Unit Price" << endl << endl; 
    cout << left << setw(25) << bookTitle 
        << left << setw(5) << bookQuantity
        << right << setw(10) << unitPrice << endl << endl;
    cout << left << setw(30) << "Subtotal " << right << setw(10) << subTotal << endl;
    cout << left << setw(30) << "Tax " << right << setw(10) << tax << endl;
    cout << left << setw(30) << "Total "
        << right << setw(10) << total 
        << endl;

    cout << "\nProgram ended successfully";
    system("pause");
}    

/* Output
Enter the book's title: Midas Touch
Enter the number of copies: 32
Enter the price of the book: 49.99

Amazing Booksellers
Title                    QTY  Unit Price

Midas Touch              32        49.99

Subtotal                         1599.68
Tax                               239.95
Total                            1839.63

Program ended successfully
*/