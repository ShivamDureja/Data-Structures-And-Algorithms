#include <iostream>
#include <stack>
using namespace std;
struct Queue
{
    stack<int> input, output;
    void enQueue(int x)
    {
        input.push(x);
    }
    int deQueue()
    {
        
        if(output.empty())
        {
            while (input.empty() == false)
            {
                output.push(input.top());
                input.pop();
            }
        }

        int x = output.top();
        output.pop();
        return x;
    }
};

int main()
{
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);

    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';

    return 0;
}