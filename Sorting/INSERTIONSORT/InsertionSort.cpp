#include <iostream>   //INSERTION SORT
using namespace std;

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i]<<endl;
    }
}

void InsertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
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
    int n;
    cout << "Enter size of array";
    cin >> n;
    int arr[50];
    cout << "Enter elements of array";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Sorted array is => " << endl;
    InsertionSort(arr,n);
    display(arr,n);
    return 0;
    
}