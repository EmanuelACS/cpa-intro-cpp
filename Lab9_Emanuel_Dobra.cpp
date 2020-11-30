#include <iostream>
#include <windows.h>
#include <ctime>
using namespace std;
/**************************************************************
* Name: Emanuel Dobra
* Lab Exercise#9: for loops
Format: for (initialize;condition;increment)
**************************************************************/
int main()
{
	int number, ctr, countdown;
	system("color 5F"); //change the console colour to something you like
	srand((unsigned)time(0)); //start the random number generator
    //#1 rewrite the following while loop using a for loop. 
	ctr = 1; //initialze
	while (ctr < 4) //loop condtion
	{
		cout << ctr << " ";
		ctr++; //incrment
	}
	cout << "Go!" << endl;

    for (ctr=1;ctr<4;ctr++)
        cout << ctr << " ";
    cout << "Go!" << ctr << endl;
	// #2 print your name 10 times.
	// Each name should appear on a line by itself
    for (ctr=1;ctr<=10;ctr++)
        cout << "Emanuel Dobra" << endl;
	//#3 print the ascii values.
    // What is an upper case A=65 What is a lower case a=97
	for (ctr = 0; ctr <= 255; ctr++)
		cout << ctr << "= " << char(ctr) << endl;
	cout << endl << endl;
	//#4 print todays temperature using degrees symbol
    cout << "Temp: 3" << char(248) << endl;
	//#5 Use a for loop to print a 5 asterisks values across the screen
    for(ctr=1;ctr<=5;ctr++)
        cout << char(42);
    cout << endl << endl;
	//#6 Complete the following loop that counts backwards from 10 to 0
    for (countdown=10; countdown>0;countdown--)
	{
	 cout << countdown << " " // 10 9 8
	 << char(7); //beep!
	 Sleep(240); //wait a couple of seconds
	}
	
	cout << "Blast off!" << endl<< endl;

	//#7 Complete the following loop instructions that
	// will print the odd numbers from 1 to 20
	cout << "Odd numbers are: " << endl;
	for (ctr=1; ctr<20; ctr+=2)
	    cout << ctr << " " ;
	cout << endl<< endl;

	//#8 Complete the rest of the code that helps
	// someone practice their multiplication table.
	int number2, answer, correctAnswer, score = 0;
	char type;
	cout << "Arithmetic Drill Time";
	number = rand() % 10 + 1; //generate a number from 1-10
	cout << "What do you want to practice * / + - ? ";
	cin >> type;
    while (type!='*' && type!='+' && type!='-' && type!='/')
    {
        cout << "Error, you must enter a * / + - , re-enter ";
        cin >> type;
    }

	//write the code that will validate the type (*, +, - or /) using a while loop
	for (ctr=1; ctr<=10; ctr++) //ask 10 questions
	{
		number2 = rand() % 10 + 1;
		cout << "what is " << number << type << number2 << "? ";
		cin >> answer;
		//write the code that will validate answer. Check for input fail only
        while(cin.fail()) {
            cout << "You must enter an int ";
            cin.clear();
            cin.ignore(80, '/n');
            cin >> answer;
        }
		//add the nested if that will compute the correctAnswer, based on the type
        if(type=='*')
            correctAnswer = number*number2;
        else if (type=='/')
            correctAnswer = number/number2;
        else if (type=='+')
            correctAnswer = number+number2;
        else 
            correctAnswer=number-number2;
		//add an if statement that will compare the user's answer with the correct answer.
		//if correct, add 1 to score
        if (answer==correctAnswer)
            score++;
	}
	cout << "your score is " << score << endl;
	//#9 prints a row of big stars across the screen. Try printing another character using char values.
	cout << endl;
	for (ctr = 0; ctr < 20; ctr++)
		cout << char(220) << char(249) << ' ';
	cout << endl;
	for (ctr = 0; ctr < 20; ctr++)
		cout << char(222) << char(251) << ' ';
	cout << endl << endl;

	cout << endl << "Program ended successfully" << endl;
	system("pause");
}