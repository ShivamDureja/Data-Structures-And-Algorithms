//Insertion sort is useful when number of elements is small

#include <iostream>   //INSERTION SORT
using namespace std;  //Time complexity O(n^2)

void display(int arr[], int n)   //function to display elements of array
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i]<<endl;
    }
}

void InsertionSort(int arr[], int n)   
{
    for (int i = 1; i < n; i++)      //loop that iterates over array
    {
        int current = arr[i];
        int j = i - 1;
        while (arr[j] > current && j >= 0)   
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
}

int main()
{
    int arr[50] = {8,1,4,1,5,9,2,6,5};
    cout << "Sorted array is => " << endl;
    InsertionSort(arr,9);
    display(arr,9);
    return 0;
    
}