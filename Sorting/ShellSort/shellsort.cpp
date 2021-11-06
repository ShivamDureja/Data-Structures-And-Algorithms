#include <iostream>  //Shell sort complexity=> (O(nlogn))
using namespace std;

void ShellSort(int A[], int n)
{
    int gap, i, j, temp;
    for (gap = n / 2; gap >= 1; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            temp = A[i];
            j = i - gap;
            while (A[j] > temp && j > 0)
            {
                A[j + gap] = A[j];
                j = j - gap;
            };
            A[j + gap] = temp;
        }
    }
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
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
    ShellSort(arr, n);
    display(arr, n);
    return 0;
}