#include<iostream>
using namespace std;

void Merge(int A[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    int B[100];
    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k++] = A[i++];
        }
        else
        {
            B[k++] = A[j++];
        }
    }
    while (i <= mid)
    {
        B[k++] = A[i++];
    }
    while (j <= high)
    {
        B[k++] = A[j++];
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}

void RecMergesort(int A[],int l,int h){
    int mid;
    if(l<h){
        mid=(l+h)/2;
        RecMergesort(A,l,mid);
        RecMergesort(A,mid+1,h);
        Merge(A,l,mid,h);
    }
}
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}

int main(){
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
    RecMergesort(arr,0,n-1);
    display(arr, n);

    return 0;
}