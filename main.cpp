#include <iostream>
#include <SortingAlgo.h>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    SortingAlgo<double> sorting;
    double arr[10];

    srand(time(0));

    cout << "Before sorting: [ ";
    for(int i = 0; i < 10; i++){
        arr[i] = rand() % 1000 / 100.0;
        cout << arr[i] << " ";
    }
    cout << " ]" << endl << endl;

    // Uncomment to test.
    // sorting.bubbleSort(arr, 10);
    // sorting.selectionSort(arr, 10);
    // sorting. recursiveBubbleSort(arr, 10);
    // sorting.insertionSort(arr, 10);
    // sorting.recursiveInsertionSort(arr, 10);
    // sorting.mergeSort(arr, 10);
    sorting.quickSort(arr, 10);

    cout << "After sorting: [ ";
    for(int i = 0; i < 10; i++){
        cout << arr[i] << " ";
    }
    cout << " ]" << endl;

    return 0;
}
