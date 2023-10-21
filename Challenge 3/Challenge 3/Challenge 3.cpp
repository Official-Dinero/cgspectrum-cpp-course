#include <iostream>
using namespace std;

int main()
{
    int CurrentYear;
    cout << "Please enter the current year: ";
    cin >> CurrentYear;

    if (CurrentYear % 400 == 0 || (CurrentYear % 4 == 0 && CurrentYear % 100 != 0))
    {
        cout << "It is a Leap Year.";
    }
    else
    {
        cout << "It is not a Leap Year.";
    }
}