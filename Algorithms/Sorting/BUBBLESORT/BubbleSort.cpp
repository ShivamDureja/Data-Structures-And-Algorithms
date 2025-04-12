#include <iostream> //BUBBLE SORT IN ITERATIVE MANNER
using namespace std;//

void Bubblesort(int arr[], int n)
{
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n - 1 - j; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp;
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
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
    Bubblesort(arr, n);
    for (int j = 0; j < n; j++)
    {
        cout << arr[j] << endl;
    }
}