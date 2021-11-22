#include <iostream>
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

int main()
{
    treecreate();
    cout<<"Tree is "<<endl;
    preorder(root);

    return 0;
}