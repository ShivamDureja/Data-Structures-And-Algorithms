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
    struct Node *ptr = p;
    while (ptr->next)
    {
        cout << ptr->data << " => ";
        ptr = ptr->next;
    }
}

Node * PartitionLL(Node *head, int x)
{
    struct Node *small = NULL;
    struct Node *high = NULL;
    struct Node *small_head = small;
    struct Node *high_head = high;

    while (head != NULL)
    {
        if (head->data < x)
        {
            small_head->next = head;
            small_head = small_head->next;
        }
        else
        {
            high_head->next = head;
            high_head = high_head->next;
        }
        head = head->next;
    }
    high_head->next = NULL;
    small_head->next = high->next;
    return small->next;
}

int main()
{
    int n, A[50];
    struct Node * temp;
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
    int x;
    cout<<"Enter partition value:"<<endl;
    cin>>x;
    cout<<"Linked List after partition"<<endl;
    temp = PartitionLL(first,x);
    Display(temp);


    return 0;
}