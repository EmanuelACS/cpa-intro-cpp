#include <iostream>
#include <ctime> //need this header file for the random number generator
using namespace std;
// Name: Emanuel Dobra
// Lab ex#7 Nested If
// Black Jack Game
// for simplicity, the dealer only gets 1 point for Ace, not 11
int main()
{
    //////////////////////////////////////////////////////////housekeeping
    int card1, card2, card3 = 0, score = 0, dealer;
    char reply;
    srand((unsigned)time(0));//start the random number generator
    system("color 5A"); //change the console colours
    cout << " " << char(35) << char(36) << char(37) << char(38) << endl;
    cout << "Let's play Black Jack! " << endl;
    cout << "The object of this game is to get 21 and not go over. " << endl;
    ///////////////////////////////////////////////////////////input
    cout << "The first card dealt is: ";
    card1 = rand() % 10 + 1; //deal the first card // Random number from 1-10
    //add an if statement to print Ace if the card is 1 otherwise print its face value
    if (card1 == 1)
        cout << "Ace";
    else
        cout << card1; //print the face value of the first card
    cout << endl;
    cout << "The second card is: ";
    card2 = rand() % 10 + 1; //deal the second card
     //add an if statement to print Ace if the card is 1 otherwise print its face value
    if (card2 == 1)
        cout << "Ace";
    else
        cout << card2; //print the face value of the first card
    cout << endl;
    dealer = rand() % 10 + 1;
    cout << "The dealer's first card is " << dealer;
    cout << endl << "Would you like another card (y/n)?";
    cin >> reply;
    //add an if statement to check if y was entered. if y then deal the third card
    //hint: the code will be the same as for card 1 and card 2
    if (reply == 'Y' || reply == 'y') {
        cout << "The third card is: ";
        card3 = rand() % 10 + 1; //deal the second card
        if (card3 == 1)
            cout << "Ace";
        else
            cout << card2; //print the face value of the first card
        cout << endl;
    }
    ///////////////////////////////////////////////////////processing
    //calculate your score i.e. add the 3 cards and store the answer in score
    score = card1 + card2 + card3;
    cout << "Your score is " << score << endl;
    ///////////////////////////////////////output
    //In Black Jack if you go over 21, you automatically lose:
    // add an if statement that checks if the score is more than 21.
    // if it is, display dealer won!
    if (score > 21)
        cout << "Dealer won!" << endl;
    //otherwise, add an else and a brace bracket add a closing bracket before the game is over
    //In BlackJack, an ace can be worth 1 point or 11 points.
    //Let's add the code to change the Ace to have a face value of 11 if score won't go over 21:
    //if either card is an ace and if the score is less than or equal to 11, add 10 to the score
    //and redisplay your new score
    else {
        if ((score + 10) <= 21) {
            if (card1 == 1 || card2 == 1 || card3 == 1) {
                score += 10;
                cout << "Your score is " << score << endl;
            }
        }
    }
    dealer += rand() % 10 + 1; //give the dealer 1 more card
    //if the dealer's score is less than or equal to 16, then the dealer must draw another card
    //add an if statement that checks the dealer's score, if it is less than or equal to 16,
    //deal another card and display the new score.
    if (dealer <= 16)
        dealer += rand() % 10 + 1;
    cout << "The dealer's score is " << dealer << endl;
    //If the dealer has more than 21, the dealer automatically loses:
    // add an if statement that checks if the dealer score is more than 21.
    // if it is, display you won!
    if (dealer > 21)
        cout << "Dealer went over 21. You won!";
    // If your score is more than the dealer's
    // display you won!
    else if (score > dealer)
        cout << "Your score is greater than the dealer. You won!";
    // otherwise
    // display dealer won!
    else
        cout << "Dealer won!";
    cout << endl << "Game over " << endl;;
    system("pause");
}
/* Output
 #$%&
Let's play Black Jack!
The object of this game is to get 21 and not go over.
The first card dealt is: 8
The second card is: Ace
The dealer's first card is 2
Would you like another card (y/n)?n
Your score is 9
Your score is 19
The dealer's score is 12
Your score is greater than the dealer. You won!
Game over
Press any key to continue . . .
*/