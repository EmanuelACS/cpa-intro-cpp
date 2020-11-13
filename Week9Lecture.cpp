#include <iostream>
#include <iomanip>
#include <string>


// Learn the use of !cin.eof()
int sum = 0
int num; 
cout << "enter a number ";
cin >> num;
while (!cin.eof()) { // Returns false only if user enters ctrl+z
    sum += num
    cout << "enter another number, or press ctrl+z to quit";
    cin >> num;
}

system("pause");