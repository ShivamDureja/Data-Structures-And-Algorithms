#include <iostream> //remove duplicates from unsorted linked list
#include <set>
using namespace std; //METHOD-1- USING HASHING
                     //METHOD-2- USING LOOPS
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

//remove duplicates while using hashing O(N) time
void removeDuplicates1(struct Node *start)
{
    set<int> seen;
    struct Node *curr = start;
    struct Node *prev = NULL;
    while (curr != NULL)
    {
        if (seen.find(curr->data) != seen.end())
        {
            prev->next = curr->next;
            delete (curr);
        }
        else
        {
            seen.insert(curr->data);
            prev = curr;
        }
        curr = prev->next;
    }
}
//removing duplicates using two loops O(1) space but O(N^2) time

void removeDuplicates2(struct Node *start)
{
    struct Node *ptr1, *ptr2, *dup;
    ptr1 = start;

    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;
        while (ptr2->next != NULL)
        {
            if (ptr1->data == ptr2->next->data)
            {
                ptr2->next = ptr2->next->next;
                delete (dup);
            }
            else
            {
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
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
    cout << "After removing duplicates from ll" << endl;
    
    removeDuplicates2(first);
    Display(first);

    return 0;
}