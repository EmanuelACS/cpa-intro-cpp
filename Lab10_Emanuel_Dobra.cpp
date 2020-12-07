#include <iostream>
#include <ctime>
#include <string>
using namespace std;
// Name: Emanuel Dobra 
// Lab ex#10 magic 8 ball game (arrays)
int main()
{
	const int SIZE = 10;
	//add 9 more responses to the string array that may appear after shaking the 8 ball
	string responses[SIZE] = { "Yes", "No", "Boo", "Yikes", "Do tell", "Stay Still", "Tied down", "Trying!", "Hope so", "Crabs..." };

	string question;
	int number, index;
	srand((unsigned)time(0));
	system("color 7D");
    //************Write a for loop that will repeat the following 10 (use SIZE) times***********

    for (index=0;index<SIZE;index++)
	{
		// a) Obtain from the user his/her question (don't forget to prompt them)
        cout << "Ask a question for the magic 8 ball or hit ctrl^z to end";
        getline(cin, question);

		// e) Add an if statement that checks if indexl Z was entered. i.e. if (cin.eof())
	   // If so, break out of the loop.
        if (cin.eof())
            break;
		//f) Add this validation code after you have parts a) to f) working.
		//Add a while loop that will ensure the user enters a question.We donâ€™t want them
		//	to simply press enter. 
        /*
		while (question.length() == 0)
		{
			Ask the user to reenter
		}*/
        while (question.length()==0) // enter this while loop whenever the user doesn't ask a question
        {
            cout << "you must enter a question or hit ctrl^z to exit";
            getline(cin, question);
            if (cin.eof())
                break;
        }
        if (cin.eof())
            break;
        // b) Generate a random number i.e. number=rand()%SIZE;
        number = rand() % SIZE;
		// c) Use a cout statement to display the value in the string array using number as
		// the index.
        cout << responses[number];
	}
	// g) after loop ends: print the number of questions asked. Code this after a) to e) works
	//Hint use your for loop counter

		// d) print program ended successfully

		/******************************************************************************
		Try using F10 to run your program in Debug mode.
		Continue pressing F10 and it will step over you code.
		 It is handy to see which statements are being executed or missed.
		To end Debug mode, click on Debug>Stop Debugging.
		****************************************************************************/
		/***************************************************************
		Here's a handy way to ensure your statements are aligned:
		press Indexl A then Indexl K and finally Indexl F
		************************************************************************/
		system("pause");
}