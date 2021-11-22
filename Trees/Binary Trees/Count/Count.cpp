#include <iostream>       //Creating and counting nodes
#include "Queue.h"         //To find nodes with deg(1) use XOR (^) in c++.
using namespace std;

struct Node *root = NULL;

void treecreate()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);

    cout << "Enter the value of root ";
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

int Count(struct Node *p){              //all nodes
    int x,y;
    if(p!=NULL){
        x=Count(p->lchild);
        y=Count(p->rchild);
        return x+y+1;
    }return 0;
}

int CountLeafNodes(struct Node *p){    //deg(0)
    int x,y;
    if(p!=NULL){
        x=Count(p->lchild);
        y=Count(p->rchild);
        if(p->lchild == NULL && p->rchild == NULL){
            return x+y+1;
        }else{
            return x+y;
        }
        }
        return 0;
}

int Height(struct Node *p){
    int x=0,y=0;
    if(p==0){
        return 0;
    }
    x=Height(p->lchild);
    y=Height(p->rchild);
    if(x>y){
        return x+1;
    }else{
        return y+1;
    }

}

int main()
{
    treecreate();
    cout<<"Tree is "<<endl;
    preorder(root);
    cout<<"No. of nodes in tree "<<Count(root)<<endl;
    cout<<"No. of leaf nodes in tree "<<CountLeafNodes(root)<<endl;
    cout<<"Finally Height of our tree is -> "<<Height(root)<<endl;

    return 0;
}