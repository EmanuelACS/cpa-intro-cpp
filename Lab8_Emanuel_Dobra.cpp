#include <iostream>
#include <string>
#include <ctime>
using namespace std;
/*Lab ex#8: Snakes and ladders
we will randomly roll die for the computer, player will input value
the game goes up to 10 (not 100) and only has 1 snake and 1 ladder
for simplicity, the computer isn’t effected by snakes or ladders */
int main()
{
    int computer=0, player=0;//player and computer's position on board 1-10
    int die;
    int snake, ladder;
    string name;
    srand((unsigned) time(0)); //start the random number generator
    system("color 2E"); //change the console colours
    cout << "What is your name? ";
    getline(cin,name);
    cout << char(1) << " Hello " << name << " welcome to snakes & ladders! "
        << char(1) << endl;
    // While pc < 10 and player < 10, continue
    while (computer < 10 && player < 10)
    {
        cout << "Roll your die - what is its value? ";
        cin >> die;
        //write a while loop that will validate user input, by ensuring the value of die is 1-6,
        //allow the user to reenter if invalid
        while (die < 1 || die > 6 || cin.fail()) { //cin.fail() if we get a NaN value
            cin.clear(); // Removes bad data from input
            cin.ignore(80, '\n');
            cout << "Error: die must have a value from 1-6, please re-enter";
            cin >> die;
        }
        cin.ignore(80, '\n');
        //add an if statement that checks if the die + current position is over 10,
        //if true tell player he/she can't make the move
        if (die + player > 10) 
            cout << "Move can't be made";
        else //otherwise (player can move)
        {
            player += die; //add the die to current player's position:
            //if player has 10, don’t allow the computer to move,
            //end the game (break out of loop)
            if (player == 10) 
                break;
            snake = rand()%9+1; //randomly generates the position for the snake
            //add an if statement that checks if landed on a snake:
            //if the player’s position is the same as the snake,
            // inform the player and reposition to 1
            if (player == snake) {
                cout << "You landed on a snake, go back to the start" << endl;
                player == 1;
            }
            else 
            {
                ladder = rand()%8+1;//randomly generates the position (1 - 8)
                //if the player lands on a ladder,
                //inform the player and reposition to 9
                if (player == ladder) {
                    cout << "You landed on a ladder, move to position 9!" << endl;
                    player == 9;
                }
            } //end if (ladder)
        } //end if (player’s move)
        //computer’s turn
        die = rand()%6+1; //randomly generates roll of die for the computer
        //Check if computer can make move:
        //Add an if statement that checks if the die + computer’s position is over 10,
        // if true tell player that the computer can't move
        if (die+computer > 10)
            cout << "";
        //otherwise (computer can move)
        else 
            computer += die; //add the die to current computer’s position:
        cout << "Your position is " << player << " My position is " << computer <<endl;
    } //end while loop
    if (player == 10) 
        cout << "Congratulations, you won!" << endl;
    else 
        cout << "Sorry, but I win!" << endl;
    cout << endl << "game over " << endl;
    system("pause");
}
/**
 * DONE, put output, improve game...
 * 
*/