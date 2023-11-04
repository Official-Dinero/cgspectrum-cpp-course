#include <iostream>
using namespace std;

int main()
{
    int NumberInput;
    cout << "Enter a positive integer:\n";
    cin >> NumberInput;
    cout << "The factors are: ";

    for (int i = 1; i <= NumberInput; i++)
    {
        if (NumberInput % i == 0)
        {
            cout << i << " ";
        }
    }
}
