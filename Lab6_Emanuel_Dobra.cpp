#include <iostream>
#include <iomanip>
#include <string>
#include <ctime> //necessary for random number generator
#include <fstream>
using namespace std;
//Name: Emanuel Dobra
//Lab ex#6:guessing game = 
//allow the user 2 guesses only, write an assessment to a file

int main()
{
	//housekeeping
	int guess, number;
	int noTries = 0;
	string name;
	bool guessedNum = false;
	srand((unsigned)time(0)); //start the random number generator
	ofstream fout("guess.out");
	//add an if statement to ensure the file opened successfully
	if (!fout.is_open())
	{
		cout << "error opening file";
		system("pause");
		exit(-1);
	}
	number = rand() % 10 + 1; //randomly generate the computer's guess
	//input
	cout << "what is your name? ";
	getline(cin, name);
	cout << "Hello " << name << " Let's play the guessing game! " << endl;
	cout << "I am thinking of a number from 1-10 Can you guess it?";
	cin >> guess;
	//processing
	//add an if statement to check if didn't guess it correctly
	if (guess != number)
	{
		//add one to the number of tries
		cout << "Wrong. Guess again ";
		cin >> guess;
		noTries++;
	}
	if (guess == number) {
		cout << char(1) << " You guessed it! "; //look what char(1) does!!!
		guessedNum = true;
	}
	else
		cout << "Wrong! The number was " << number; //only print if didn't guess it
	cout << endl;
	//output to the file
	fout << "============================" << endl;
	fout << "results of guessing game for " << name << endl;
	fout << setw(20) << "Number to guess: " << right << setw(5) << number << endl;
	fout << setw(20) << "Number of tries: " << right << setw(5) << noTries << endl;
	//add an if to check if number was guessed first time
	if (noTries == 0)
		fout << "Good guess, you must have esp! ";
	//add an if to check if number was not guessed
	if (guessedNum == false)
		fout << "Number not guessed ";
	fout << endl;
	fout << "============================" << endl;
	cout << "Game over" << endl;
	system("type guess.out");
	system("pause");
}
/* Output
what is your name? Emanuel
Hello Emanuel Let's play the guessing game!
I am thinking of a number from 1-10 Can you guess it?5
Wrong. Guess again 4
Wrong! The number was 1
Game over
============================
results of guessing game for Emanuel
   Number to guess:     1
   Number of tries:     1
Number not guessed
============================
Press any key to continue . . .

*/