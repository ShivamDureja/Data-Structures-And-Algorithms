#include <iostream>     //Circular Queue (front and rear are moved to 0 after end point)
using namespace std;

struct Queue
{
    int size;
    int front;
    int rear;
    int *s;
};

void enqueue(Queue *q, int x)
{
    //check if queue is full
    if((q->rear+1)%q->size == q->front){
        cout<<"Queue is full!!";
    }
    else{
        q->rear=(q->rear+1)%q->size;
        q->s[q->rear] = x;
    }
};

int dequeue(Queue *q)
{
    int x=-1;
    //check if queue is empty
    if(q->front == q->rear){
        cout<<"Queue is already empty!!";
    }
    else{
        q->front = (q->front+1)%q->size;
        x=q->s[q->front];
    }
    return x;
}

void Display(Queue *q)
{
    for (int i = q->front+1; i <= q->rear; i++)
    {
        cout << q->s[i] << endl;
    }
}

int main()
{

    struct Queue q ;
    cout << "Enter size of queue";
    cin >> q.size;
    q.front = q.rear = -1;
    q.s = new int[q.size];

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    Display(&q);

    cout<<dequeue(&q);

    return 0;
}