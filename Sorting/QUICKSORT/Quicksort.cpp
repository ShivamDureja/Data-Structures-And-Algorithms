//Time Complexity Best Case- O(n^2)
//Worst and Avg case- O(N logN)
#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int A[], int l, int h)
{
    int pivot = A[l];
    int i = l, j = h;

    do
    {
        do
        {
            i++;
        } while (A[i] <= pivot);
        do
        {
            j--;
        } while (A[j] > pivot);
        if (i < j)
        {
            swap(&A[i], &A[j]);
        }}
        while (i < j);
            
        swap(&A[l], &A[j]);
        return j;
    
}

void QuickSort(int A[], int l, int h)
{
    int j;
    if (l < h)
    {
        j = partition(A, l, h);
        QuickSort(A, l, j);
        QuickSort(A, j + 1, h);
    }
}

void Display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}

int main()
{
    int n,arr[50];
    cout<<"Enter Size =>";
    cin>>n;
    cout<<"Enter elements of array =>";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Sorted array is => "<<endl;
    QuickSort(arr,0,n);
    Display(arr,n);

    return 0;
}