#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

// Emanuel Dobra

int main() {
    int test[5] = {30, 50, 60, 70, 80};
    cout << test[3] << endl; 
    
    char letters[26];
    cout << "-" << letters[4] << endl;

    const int SIZE = 5;
    int grades[SIZE];
    string students[SIZE];
    int length;
    for (length = 0; length < 5; length++) {
        cout << "enter a grade or hit ctrlZ to exit ";


        cout << "enter a grade";
        cin >> grades[length]; 
        if (cin.eof())
            break;
    }
    cout << "number of elements assigned: " << length << endl;
    system("pause");
}