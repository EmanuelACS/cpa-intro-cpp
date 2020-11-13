#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
/* Name: Emanuel Dobra      Lab Exercise #3: input/output

If you like, you can complete this exercise on your own. I will walk through the changes
during the lab. You can check to see if you’re doing it right.
The following program asks a user for their name and the number of text messages sent.

It then computes the cost for the text messages and prints the following:
<-------20-----><----10---><-----10-----><-----10----->
Name             # of texts     Cost/text    Total Cost

J. Doe                   40           .10          4.00
*/

int main()
{
    //housekeeping: declare variables, a constant for cost per text and set output rules
    const double TEXT_COST=32.0;
    string name;
    int noTexts;
    double totalCost;

    cout << fixed << setprecision(2); // print in non scientific notation

    //input: ask user for name and number of text messages
    cout << "What is your name? ";
    getline(cin, name);
    cout << "Enter number of texts ";
    cin >> noTexts;

    //processing: compute cost by multiplying number of texts by cost per text
    totalCost = noTexts * TEXT_COST;

    //output: align data in columns, add a blank line after the title, left justify name
    cout << left << setw(20) << "Name" 
        << right << setw(10) << "# of texts" 
        << setw(10) << "Cost/text" 
        << setw(10) << "TotalCost" 
        << endl;
    cout << left << setw(20) << name 
        << right << setw(10) << noTexts 
        << setw(10) << TEXT_COST 
        << setw(10) << totalCost 
        << endl;

    cout << endl<< "Program ended successfully" << endl;
    system("pause");
}

/* Output
What is your name? Emanuel D.
Enter number of texts 3
Name                # of texts Cost/text TotalCost
Emanuel D.                   3     32.00     96.00

Program ended successfully
*/