/*Create getmin() funct to return min value in stack with O(1) time. */
//This Approach uses Modified values in O(1) time and O(1) space.

#include <iostream>
#include <stack>
using namespace std;

struct MyStack
{
    stack<int> s;
    int mini;

    void push(int x)
    {
        if (s.empty())
        {
            mini = x;
            s.push(x);
            cout << "Number inserted" << x << endl;
            return;
        }
        else if (x < mini)
        { //if x less than mini insert modified value
            s.push(2 * x - mini);
            mini = x; //update min.
        }
        else
        {
            s.push(x);
        }
        cout << "Value inserted " << x << endl;
    }

    void pop()
    {
        if (s.empty())
        {
            cout << "Stack already empty" << endl;
            return;
        }
        int t = s.top();
        s.pop();
        cout<<"Element popped out!!"<<endl;
        if (t < mini)
        {
            mini = 2 * mini - t;
        }
    }

    void getMin()
    {
        if (s.empty())
        {
            cout << "Stack is empty " << endl;
        }
        else
        {
            cout << "Min element is " << mini << endl;
        }
    }
};




int main()
{
    MyStack s;
    s.push(3);
    s.push(5);
    s.getMin();
    s.push(2);
    s.push(1);
    s.getMin();
    s.pop();
    s.getMin();
    s.pop();
    s.getMin();
    
    return 0;
}