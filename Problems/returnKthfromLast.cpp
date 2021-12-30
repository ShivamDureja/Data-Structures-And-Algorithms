#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

//creating a linked list

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

//Displaying a linked list

void Display(struct Node *p)
{
    while (p != NULL)
    {
        cout << p->data << " => ";
        p = p->next;
    }
}

Node *returnKthLast(Node *head, int k)
{                               /* Iterative approach: Consider two pointers p1 and p2 with
                                k distance apart. when p1 hits end then other is at the req element.*/
    Node *p1 = head;            //It takes O(N) time with O(1) space.
    Node *p2 = head;           /* Recursive approach: The algo recurses through ll. When it hoots end
                                it passes back a counter set to 0. when counter == k return that element*/

    //move p1 with k distance
    for (int i = 0; i < k; i++)
    {
        if (p1 == NULL)
            return NULL;
        p1 = p1->next;
    }

    //move both with same pace
    while (p1 != NULL)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p2;
}

int main()
{
    int n, A[50];
    struct Node *temp;
    cout << "Enter size of LL";
    cin >> n;
    cout << "Enter elements of LL";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    create(A, n);
    cout << "Here is your linked list=>" << endl;
    Display(first);
    int k;
    cout<<"Enter the value of k"<<endl;
    cin>>k;
    temp = returnKthLast(first,k);
    cout<<"Kth from last is "<<endl;
    int x = temp->data;
    cout<<x<<endl; 

    return 0;
}