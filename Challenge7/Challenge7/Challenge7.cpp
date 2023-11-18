#include <iostream>

using namespace std;

int main()
{
	int aValue;
	int bValue;

	cout << "Enter the value of a: " << endl;
	cin >> aValue;
	cout << "Enter the value of b: " << endl;
	cin >> bValue;

	int* ptrA = &aValue;
	int* ptrB = &bValue;

	cout << "The memory address of a is: " << ptrA << endl;
	cout << "The memory address of b is: " << ptrB << endl;

	cout << "The value of a is: " << *ptrA << endl;
	cout << "The value of b is: " << *ptrB << endl;
}
