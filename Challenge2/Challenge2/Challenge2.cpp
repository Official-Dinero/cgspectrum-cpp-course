#include <iostream>

using namespace std;

int main()
{
	float number1, number2, number3;

	cout << "Please enter 3 Numbers. \n";

	cout << "Number 1: ";
	cin >> number1;

	cout << "Number 2: ";
	cin >> number2;

	cout << "Number 3: ";
	cin >> number3;

	float sum = number1 + number2 + number3;

	cout << "The sum of your three numbers is " << sum << ". \nThe average of your three numbers is " << sum / 3.0f << ".";

}