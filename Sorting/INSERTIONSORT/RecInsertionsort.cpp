#include<iostream>
using namespace std;

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}

void RecInsertSort(int arr[],int n){
    if(n<=1){
        return;
    }
    RecInsertSort(arr,n-1);
    int last = arr[n-1];
    int j=n-2;
    while(arr[j]>last && j>=0){
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = last;
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
    RecInsertSort(arr,n);
    print(arr,n);
    return 0;
}