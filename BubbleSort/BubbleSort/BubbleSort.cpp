#include <iostream>
using namespace std;


int i, j, SizeOfArray, NumberList[100];
void QuickSort(int NumberList[], int SizeofArray);
void PrintArray(int arr[], int SizeOfArr);

int main()
{
    cout << "Enter array size: ";
    cin >> SizeOfArray;

    cout << "Enter your numbers in to the array: \n";
    for (i = 0; i < SizeOfArray; i++)
    {
        cin >> NumberList[i];
    }

    cout << "\nArray before sorting: \n";
    PrintArray(NumberList, SizeOfArray);

    QuickSort(NumberList, SizeOfArray);

    cout << "\nArray after sorting: \n";
    PrintArray(NumberList, SizeOfArray);
}


void QuickSort(int NumberList[], int SizeofArray)
{
    for (j = 0; j < SizeOfArray; j++)
    {
        for (i = 0; i < SizeOfArray - 1; i++)
        {
            if (NumberList[i] > NumberList[i + 1])
            {
                int buffer = NumberList[i];
                NumberList[i] = NumberList[i + 1];
                NumberList[i + 1] = buffer;
            }
        }
    }
}


void PrintArray(int arr[], int SizeOfArr)
{
    for (i = 0; i < SizeOfArr; i++)
    {
        cout << arr[i] << " ";
    }
}