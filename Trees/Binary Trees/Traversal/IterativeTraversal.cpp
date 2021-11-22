#include <iostream>
#include "Stack.h"
#include "Queue.h"
using namespace std;

struct Node *root = NULL;

void treecreate()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);

    cout << "Enter the value of root";
    cin >> x;
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);

    while (!isEmpty(q))
    {
        p = dequeue(&q);
        cout << "Enter left child of "<<p->data << endl;
        cin >> x;
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        cout << "Enter right child of "<<p->data << endl;
        cin >> x;
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

void preorder(struct Node *p)
{
    if (p)
    {
        cout << p->data << endl;
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void Ipreorder(struct Node *p){
    struct Stack stk;
    StackCreate(&stk,100);

    while(p || isEmptyStack(stk)){
        if(p!=NULL){
            cout<<p->data;
            push(&stk,p);
            p=p->lchild;
        }
        else{
            p=pop(&stk);
            p=p->rchild; 
        }
    }
}

int main()
{
    treecreate();
    cout<<"Tree is "<<endl;
    Ipreorder(root);

    return 0;
}