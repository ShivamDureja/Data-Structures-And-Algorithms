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
        cout << p->data<<" => ";
        p = p->next;
    }
}

//Recursive display of linked list

void RecDisplay(struct Node *p){
    if(p!=NULL){
       cout << p->data<<" => ";
       RecDisplay(p->next); 
    }
}


int main()
{
    int n, A[50];
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

    return 0;
}