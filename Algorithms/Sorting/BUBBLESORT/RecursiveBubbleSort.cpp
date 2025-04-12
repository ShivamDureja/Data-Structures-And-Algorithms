#include <iostream>
using namespace std;

void RecBubble(int arr[], int n)
{
    if (n == 1)
    {
        return; //BaseCASE
    }
    for (int i = 0; i < n; i++)
    {

        if (arr[i] > arr[i + 1])
        {
            int temp;
            temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }
    RecBubble(arr, n - 1);
}

int main()
{
    int n, arr[50];
    cout << "enter size of array =>";
    cin >> n;
    cout << "Enter the elements of array";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    RecBubble(arr, n);
    cout << "Sorted array is => ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}