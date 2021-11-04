#include <iostream>
using namespace std;

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void Selectionsort(int A[], int n)
{
    int i, j, k, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = k = i; j < n; j++)
        {
            if (A[j] < A[k])
            {
                k=j;
            }
        }
        swap(&A[i], &A[k]);
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
    int n, arr[50];
    cout << "Enter size of array =>" << endl;
    cin >> n;
    cout << "Enter elements of array =>" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Selectionsort(arr, n);
    cout << "Sorted array is =>" << endl;
    Display(arr, n);

    return 0;
}