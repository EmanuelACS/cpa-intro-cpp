#include <iostream>
using namespace std;
//Name: Emanuel Dobra   Lab ex#2: Practice with the assignment statement
int main() 
{
    //program example #1 using doubles
    cout << "program example#1 " << endl;
    double amount=10;    //notice in the error list, under warnings it tells you that you're assigning an 
    //int to a double, called coercion. Avoid coercion by adding a decimal point
    cout << "amount is "<< amount << endl;
 

    //program example #2 shows integer arithmetic: addition 
    cout << endl << "program example#2 " << endl; 
    int numb=100.7; //coercion, assigning an double to an int. 
    cout << "numb is "<< numb << endl;  //What happens to the .7? 
  

    //program example #3 computes the area of a triangle using the formula:  1/2basexheight 
    cout << endl<<"program example#3 " << endl; 
    double area,base,height; 
    //write the statements that will assign values to base and height 
    base = 25.0;
    height = 35.5;
    //add the statement that computes the area using the 
	//formula area= 1/2basexheight     
    area = (base * height) / 2;
    //print the area     
    cout << endl << "The area is " << area << endl;
    //Check your answer with the calculator


    //program example #4 shows division and remainder(%) 
    cout << endl << "program example#4 " << endl; 
    //add the code that will print 11 divided by 3 
    cout << endl << "11 divided by 3 is: " << 11.00/3.00 << endl;
    //add the code that will print the remainder of 11 divided by 3.
    cout << endl << "the remainder of 11 divided by 3 is: " << 11%3 << endl;


    //Suppose you have $3.85 in pocket change. How many quarters could you have? 
    //How much change after the quarters are spent? 
    //Declare and assign this to a variable called change. We will use cents only no dollars. 
    int change=385, quarters=25, cents=1; 
    int quarterValue = 25;
    //Print the number of quarters there are. 
    quarters = change/quarterValue;
    cout << endl << "There can be " << quarters << " quarters" << endl;
    //Hint: find the number of quarters by dividing change by 25. 
	//Print the number of cents left over.
	cents = change%quarterValue;
	cout << endl << "There could be " << cents << " cents left" << endl;
	//Hint: find the remainder after dividing change by 25.
    cout << endl << "program ended successfully " << endl; 
    system("pause"); 
 }