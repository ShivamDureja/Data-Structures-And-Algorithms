#include<stack>
#include <iostream> //Check the palindrome in a linked list
using namespace std;//APPROACH 1: REVERSE AND COMPARE
                    //APPROACH 2: ITERATIVE USING STACK
struct Node         //APPROACH 3: RECURSIVE APPROACH

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
        cout << p->data << " => "<<endl;
        p = p->next;
    }
}

struct Node * reverseLL(struct Node *head)
{
    Node *current = head;
    Node *prev = NULL;
    Node *next = NULL;
    while (current != NULL)
    {
        next = current->next; //store the next of current
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

bool isEqual(struct Node *one,struct Node * two)
{
    struct Node *temp1 = one,*temp2 = two;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->data != temp2->data){
            return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    
    return true;
}

bool chkPalindrome(struct Node * head){
    struct Node * reversed = reverseLL(head);
    return isEqual(head,reversed);
}


bool isPallindromeUsingStack(struct Node * head){
    struct Node * slow = head;
    stack <int> s ;
    while(slow != NULL){
        s.push(slow->data);  //pushing elements in a stack
        slow = slow->next;
    }

    while(head!=NULL){
        int i = s.top();
        s.pop();
        if(head->data != i){  //check elements from stack
            return false;
        }
        head = head->next;
    }
    return true;

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
    cout << "Chk palindrome-" << endl;
    
    if (isPallindromeUsingStack(first))
    {
        cout << "LL is a palindrome" << endl;
    }
    else
    {
        cout << "It is not a palindrome" << endl;
    }

    return 0;
}