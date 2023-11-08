#include <iostream>

using namespace std;

// function for counting missing elements.
void countMissingElements(int *array, int size, int &count)
{
    int i = 0;
    int initialDiff = array[i] - i;
    while (i < size)
    {
        if (initialDiff != array[i] - i)
        {
            while (initialDiff < array[i] - i)
            {
                count++;
                initialDiff++;
            }
        }
        i++;
    }
}

void printMissingElements(int *array, int size)
{
    cout << "The missing elements in the array are printed below." << endl;
    int initialDiff = array[0] - 0; // set up the initial difference value
    for (int i = 0; i < size; i++)
    {
        if (initialDiff != array[i] - i)
        {
            while (initialDiff < array[i] - i)
            {
                if (initialDiff == array[0] - 0)
                { // check if this is the fist missing element
                    cout << i + initialDiff;
                }
                else
                {
                    cout << " " << i + initialDiff;
                }
                initialDiff++;
            }
        }
    }
    cout << endl;
}

// function to check whether the array is sorted or not.
bool isSequentiallySorted(int *array, int size)
{
    bool sequentiallySorted = true;
    for (int i = 0; i < size - 1; i++)
    {
        if (array[i] < array[i + 1])
        {
            continue;
        }
        else
        {
            sequentiallySorted = false;
            break;
        }
    }
    return sequentiallySorted;
}

int main()
{
    cout << "Enter the size of the array." << endl;
    cout << "Size: ";
    int size, count = 0;
    cin >> size;
    cout << "Enter the elements of the array in ascending order." << endl;
    int *array = new int[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Array[" << i + 1 << "]: ";
        cin >> array[i];
    }
    if (isSequentiallySorted(array, size))
    {
        countMissingElements(array, size, count);
        if (count > 0)
        {
            cout << count << " elements are missing in the array." << endl;
            printMissingElements(array, size);
        }
        else
        {
            cout << "No missing elements in the array." << endl;
        }
    }
    else
    {
        cout << "The array is not sequentially sorted." << endl;
    }
}