#ifndef SORTINGALGO_H
#define SORTINGALGO_H

#include <vector>
using namespace std;

/**
*    class SortingAlgo: used to sort array elements in ascending order.
*
*    Common formal parameter used :-
*    num: size of arr;
*    arr: array variable of any data type OR class
*    (but make sure overloading relational operators before using its object as argument.
**/

template <class Type>
class SortingAlgo
{
    public:
        // Select the minimum element from unsorted part and put it at the position pointed by a pointer (index).
        // Advance the pointer (pointing to the element where all the elements before
        // it are already sorted).
        // Repeat the process until the pointer points to the last element of the array.
        // Time complexity: O(n^2) where n is the size of array.
        void selectionSort(Type arr[], int num);

        // Swap the location of two adjacent element if the first element is larger than the second element.
        // This process continues for (n-1) times for each element in the array,
        // the number of time will reduce by one for each iteration.
        // TIme complexity: O(n^2) where n is the size of array.
        void bubbleSort(Type arr[], int num);

        // Recursive version of bubble sort.
        void recursiveBubbleSort(Type arr[], int num);

        // Traverse over each element and insert each element
        // into its correct positions in the sorted sub-array.
        // Time complexity: O(n^2) where n is the size of array.
        void insertionSort(Type arr[], int num);

        // Recursive version of insertion sort.
        void recursiveInsertionSort(Type arr[], int num);

        // Use recursion to divide and merge array to form a sorted array.
        // Time complexity: O(n*log n);
        void mergeSort(Type arr[], int num);

        // Use recursion.
        // Find pivot (middle position) and use it to compare with other element.
        // Sort array into two sub-array.
        // The first sub-array contains elements smaller than pivot
        // while the second sub-array contains elements which are larger than pivot.
        // Both of the sub-arrays are then be sorted using quick sort too. (Recursion)
        // Time complexity: O(n*log n);
        void quickSort(Type arr[], int num);

    // Inaccessible outside of the class.
    private:
        // Swap two values.
        void swap(Type& a, Type& b);

        // Implement recursive insertion sort.
        void recursiveInsertionSort(Type arr[], int num, int sortedElemIndex);

        // Implement recursive merge sort.
        void mergeSort(Type arr[], int first, int last);

        // Implement recursive quick sort.
        void quickSort(Type arr[], int first, int last);
};


template <class Type>
void SortingAlgo<Type>::selectionSort(Type arr[], int num){
    if(num > 1){
        // Element to be replaced by next minimum element among unsorted sublist.
        int elemToBeSorted = 0;
        // Keep track of current minimum element among unsorted sublist.
        int minIndex;
        int currentIndex;

        while(elemToBeSorted < num - 1){
            minIndex = elemToBeSorted;
            currentIndex = elemToBeSorted + 1;

            // Find minimum element among unsorted sub-array.
            while(currentIndex < num){
                if(arr[currentIndex] < arr[minIndex])
                    minIndex = currentIndex;
                currentIndex++;
            }

            // If minIndex is not equal to the elemToBeSorted,
            // Swap the value located at minIndex with the one at elemToBeSorted.
            if(minIndex != elemToBeSorted){
                Type temp = arr[minIndex];
                arr[minIndex] = arr[elemToBeSorted];
                arr[elemToBeSorted] = temp;
            }

            elemToBeSorted++;
        }
    }
}

template <class Type>
void SortingAlgo<Type>::bubbleSort(Type arr[], int num){
    // To optimize the bubble sort so that if the arr is already sorted, the loop will stop.
    bool swapped = true;

    for(int i = num - 1; i > 0 && swapped; i--){
        swapped = false;
        for(int j = 0; j < i; j++){
            // Compare two adjacent elements to determine if swap is needed.
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
    }
}

template <class Type>
void SortingAlgo<Type>::recursiveBubbleSort(Type arr[], int num){
    if(num > 1){
        for(int i = 0; i < num - 1; i++){
            if(arr[i] > arr[i+1])
                swap(arr[i], arr[i+1]);
        }
        recursiveBubbleSort(arr, num - 1);
    }
}

template <class Type>
void SortingAlgo<Type>::insertionSort(Type arr[], int num){
    if(num > 1){
        int elemToBeSorted;

        for(int i = 1; i < num; i++){
            elemToBeSorted = i;

            for(int j = 0; j < elemToBeSorted; j++){
                if(arr[j] > arr[elemToBeSorted]){
                    Type temp = arr[elemToBeSorted];

                    // Shifting elements greater than element
                    // pointed by elemToBeSorted to the right by one step.
                    for(int k = elemToBeSorted - 1; k >= j; k--){
                        arr[k+1] = arr[k];
                    }

                    arr[j] = temp;
                    break;

                }

            }

        }
    }
}

template <class Type>
void SortingAlgo<Type>::recursiveInsertionSort(Type arr[], int num){
    recursiveInsertionSort(arr, num, 1);
}

template <class Type>
void SortingAlgo<Type>::mergeSort(Type arr[], int num){
    mergeSort(arr, 0, num - 1);
}

template <class Type>
void SortingAlgo<Type>::quickSort(Type arr[], int num){
    quickSort(arr, 0, num - 1);
}

template <class Type>
void SortingAlgo<Type>::quickSort(Type arr[], int first, int last){
    if(first < last){
        // Determine pivot of the array.
        int pivot = (first + last) / 2;

        swap(arr[first], arr[pivot]);

        int smallerPart = first;
        int current = first + 1;

        while(current <= last){
            // If element currently pointed by current is smaller than pivot value,
            // swap its value with the element past-the-end of the sublist containing smaller elements.
            if(arr[current] < arr[first]){
                swap(arr[++smallerPart], arr[current]);
            }
            current++;
        }

        // Reposition pivot value to the middle where the sublist
        // to its left is smaller while its right side is larger.
        swap(arr[smallerPart], arr[first]);

        quickSort(arr, first, smallerPart - 1);
        quickSort(arr, smallerPart + 1, last);
    }
}

template <class Type>
void SortingAlgo<Type>::swap(Type& a, Type& b){
    Type temp = a;
    a = b;
    b = temp;
}

template <class Type>
void SortingAlgo<Type>::recursiveInsertionSort(Type arr[], int num, int sortElemIndex){
    if(sortElemIndex < num){

        for(int i = 0; i < sortElemIndex; i++){
            if(arr[i] > arr[sortElemIndex]){
                Type temp = arr[sortElemIndex];

                // Shifting elements which is larger than elements
                // pointed by sortElemIndex to the right by one step.
                for(int k = sortElemIndex - 1; k >= i; k--){
                    arr[k+1] = arr[k];
                }

                arr[i] = temp;
                break;
            }
        }

        recursiveInsertionSort(arr, num, ++sortElemIndex);
    }
}

template <class Type>
void SortingAlgo<Type>::mergeSort(Type arr[], int first, int last){
    if(first < last){
        // Find middle item's index.
        int middle = (first + last) / 2;
        // Divide arr to two sublists and sort them separately.
        mergeSort(arr, first, middle);
        mergeSort(arr, middle + 1, last);

        vector<Type> tempList;
        int secondList = middle + 1;
        int firstList = first;

        // Merge two sorted sublist together.
        while(firstList <= middle && secondList <= last){
            if(arr[firstList] < arr[secondList]){
                tempList.push_back(arr[firstList++]);
            }
            else if(arr[secondList] < arr[firstList]){
                tempList.push_back(arr[secondList++]);
            }
            else{
                tempList.push_back(arr[firstList++]);
                tempList.push_back(arr[secondList++]);
            }
        }

        while(firstList < middle + 1){
            tempList.push_back(arr[firstList++]);
        }

        while(secondList < last + 1){
            tempList.push_back(arr[secondList++]);
        }

        for(int i = first, j = 0; j < tempList.size(); i++, j++){
            arr[i] = tempList[j];
        }
    }
}

#endif // SORTINGALGO_H
