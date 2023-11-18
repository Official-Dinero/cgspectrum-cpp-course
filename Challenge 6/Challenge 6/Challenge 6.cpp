#include <iostream>

using namespace std;

void PopulateArray(int theArray[], int size);
void DisplayArray(int theArray[], int size);
int GetLargest(int theArray[], int size);

int main()
{
    int size;
    cout << "Please enter the size of your array: \n";
    cin >> size;
    int myArray[100];
    cout << "Please enter " << size << " numbers: \n";
    PopulateArray(myArray, size);
    int largestelement = GetLargest(myArray, size);
    cout << "The largest number in your array is: "<< largestelement << endl;
}

void PopulateArray(int theArray[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> theArray[i];
    }
}

void DisplayArray(int theArray[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << theArray[i] << " ";
    }
}


int GetLargest(int theArray[], int size)
{
    int largest = theArray[0];

    for (int i = 0; i < size; i++)
    {
        if (theArray[i] > largest)
        {
            largest = theArray[i];
        }
    }

    return largest;
}