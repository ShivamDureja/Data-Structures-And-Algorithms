#include <iostream>
using namespace std;

int findmax(int A[], int n)
{
    int i;
    int max = A[0];
    for (i = 0; i < n; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }

    return max;
}

void Countsort(int A[], int n)
{
    int max, i;
    int *c;

    max = findmax(A, n);
    c = new int[max + 1];

    for (int i = 0; i < max + 1; i++)
    {
        c[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        c[A[i]]++;
    }

    i = 0;
    int j = 0;
    while (i < max + 1)
    {
        if (c[i] > 0)
        {
            A[j++] = i;
            c[i]--;
        }
        else
        {
            i++;
        };
    };
};
void Display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
};

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
    Countsort(arr,n);
    Display(arr,n);

    return 0;
}