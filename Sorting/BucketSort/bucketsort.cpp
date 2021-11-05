#include <iostream>
using namespace std;

void print(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i]<<endl;
    };
}

int Max(int A[], int n)
{
    int max = A[0];
    for (int i = 0; i < n; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    return max;
}

//Linked List node

class Node
{
public:
    int value;
    Node *next;
};

void Insert(Node **ptrBins, int idx)
{
    Node *temp = new Node;
    temp->value = idx;
    temp->next = nullptr;

    if (ptrBins[idx] == nullptr)
    { // ptrBins[idx] is head ptr
        ptrBins[idx] = temp;
    }
    else
    {
        Node *p = ptrBins[idx];
        while (p->next != nullptr)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

int Delete(Node **ptrBins, int idx)
{
    Node *p = ptrBins[idx]; // ptrBins[idx] is head ptr
    ptrBins[idx] = ptrBins[idx]->next;
    int x = p->value;
    delete p;
    return x;
}

void Binsort(int A[], int n)
{
    int max = Max(A, n);

    //create bins array
    Node **bins = new Node *[max + 1];

    //initialize bins with null
    for (int i = 0; i < max + 1; i++)
    {
        bins[i] = nullptr;
    }
    //update count array values
    for (int i = 0; i < n; i++)
    {
        Insert(bins, A[i]);
    }
    //update A with sorted elements
    int i = 0;
    int j = 0;
    while (i < max + 1)
    {
        while (bins[i] != nullptr)
        {
            A[j++] = Delete(bins, i);
        }
        i++;
    }
    //delete heap memory
    delete[] bins;
}

int main()
{
    int n, arr[50];
    cout << "Enter Size =>";
    cin >> n;
    cout << "Enter elements of array =>";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Sorted array is => " << endl;
    Binsort(arr, n);
    print(arr, n);
    return 0;
}