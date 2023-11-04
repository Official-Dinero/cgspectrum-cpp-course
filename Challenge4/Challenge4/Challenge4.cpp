#include <iostream>
using namespace std;

float Cubed(float number);
float Input;

int main()
{
    cout << "Please enter a number: ";
    cin >> Input;
    cout << Input << " cubed is " << Cubed(Input) << "!\n";
}

float Cubed(float number)
{
    return number * number * number;
}