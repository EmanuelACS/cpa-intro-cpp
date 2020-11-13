#include <iostream> 
#include <iomanip>
using namespace std; 
 
/**********************************************************  
Name: Emanuel Dobra 
This program calculates and prints an employee's pay (Fixed)
***********************************************************/
 
int main() 
{         
    //housekeeping   
    string employeeName="Robert Goulet";  
    int employeeHours;
    double totalPay;   
    char dept;    
        
    //input   
    employeeHours=44.50;   
    dept='A';               

    //processing  
    const double PAYRATE=15.50; 
    totalPay = employeeHours * PAYRATE;

    //output  
    cout << std::fixed << std::setprecision(2);
    cout << left << setw(20) << "Name: " 
        << left << setw(10) << "Department: " 
        << right << setw(10) << "Pay: $" 
        << endl;
    cout << left << setw(20) << employeeName 
        << left << setw(10) << dept 
        << right << setw(12) << totalPay 
        << endl;        
    cout << "Program ended successfully" << endl;
    system("pause");
}

/* Output 
Name:               Department:     Pay: $
Robert Goulet       A               682.00
Program ended successfully
*/
