#include <iostream>
#include <iomanip>
#include <string>   

using namespace std;

// Emanuel Dobra 
// For loops

int main()
{
    int ctr, number=5;
    for (ctr=1;ctr<=number;ctr++) {
        cout << "Emanuel" << endl;        
    }
    cout << "ctr is " << ctr << endl;

    string password, secret = "test";
    for (ctr=0;ctr<3;ctr++){
        cout << "Enter password: ";
        getline(cin,password);
        while(!cin.eof()) {
            break;
        }
        if (password == secret) {
            break;
        }
    }
    cout << "ctr is " << ctr << endl;
    if (ctr == 3) {
        cout << "Failed to login" << endl;
        system("pause");
        exit(-1);
    }

    // Arrays /*
    int grades[3]; // holds 3 grades
    const int SIZE = 3;
    int tests[SIZE];
    //int testMarks[] = {60, 85, 94};
    //cout << "The value at index 2 is " << testMarks[2];  
    int testMarks[SIZE];
    int index, mark = 45; 
    for (index=0;index<SIZE;index++) {
        cout << "Enter the test mark # " << index+1 << endl;
        cin >> testMarks[index];
    }
    
    for (index=0;index<3;index++) {
        cout << "Your grade is " << testMarks[index] << endl;
    }
    system("pause");
}