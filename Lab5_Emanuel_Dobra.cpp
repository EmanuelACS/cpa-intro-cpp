#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;
//Name: Emanuel Dobra
//Lab Ex#5: pgm computes expenses and writes them to a file
int main()
{
	//housekeeping	
	const double ROOM_RATE = 350.00;
	string city, item;
	double balance, cost, mealCost, expenses;
	int numberDays;
	//add the code to open a file for output and set output rules
	ofstream fout("myTrip.dat");
	fout << setprecision(2) << fixed;

	//input
	cout << "enter the name of a city ";
	getline(cin, city);
	//what happens if you try to enter a description with embedded spaces?
	cout << "enter a noun ";
	getline(cin, item);
	cout << "enter a dollar amount ";
	cin >> balance;
	cout << "enter a positive number ";
	cin >> numberDays;
	cout << "enter a real number ";
	cin >> cost;
	cout << "enter a second real number ";
	cin >> mealCost;
	//processing
   /*calculate expenses by multiplying the room rate by the number of days + cost + meal
   cost
	subtract the expenses from the balances */
	expenses = ROOM_RATE * numberDays + cost + mealCost;
	balance -= expenses;
	//output
   // add the code to change cout to the output file name

	fout << "During a " << numberDays << " day vacation to " << city;
	fout << ". You book accommodations at the Marriott Resort and Spa at a cost of $"
		<< ROOM_RATE << " per night " << endl;
	fout << "While on vacation, you decide to go shopping for a(n) " << item
		<< " that costs $ " << cost << endl;
	fout << "Feeling tired from shopping, you decide to order room service and charged $ "
		<< mealCost << endl << endl;
	fout << "Your vacation expenses are summarized below." << endl << endl;
	/*add formatting to print string data left justified in a column width of 25 and
	 numeric data right justified in a column width of 10*/

	fout << left << setw(25) << "Total vacation expenses" 
		<< right << setw(10) << expenses << endl;
	fout << left << setw(25) << "Amount of money remaining" 
		<< right << setw(10) << balance << endl;

	cout << endl << "Program ended successfully" << endl;
	//Run the program, did the balance appear on the output file
	cout << endl << "Printout of mytrip.dat file" << endl << endl;
	// copy the output file to the I/O dialogue
	system("type myTrip.dat");
	system("pause");
}

/*Output
enter the name of a city Kingston
enter a noun Cat
enter a dollar amount 25
enter a positive number 40
enter a real number 20
enter a second real number 10

Program ended successfully

Printout of mytrip.dat file

During a 40 day vacation to Kingston. You book accommodations at the Marriott Resort and Spa at a cost of $350.00 per night
While on vacation, you decide to go shopping for a(n) Cat that costs $ 20.00
Feeling tired from shopping, you decide to order room service and charged $ 10.00

Your vacation expenses are summarized below.

Total vacation expenses    14030.00
Amount of money remaining -14005.00
Press any key to continue . . .
*/