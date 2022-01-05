/* Sort a stack using
    1. Recursion
    2. An auxillary Stack */

#include <iostream>         //This Approach uses an Auxillary Stack
#include <stack>            //This Algo uses O(N^2) time and O(N) space.
using namespace std;

stack<int> SortStack(stack<int> &input)
{
    stack<int> tempStack;
    while (!input.empty())
    {
        int temp = input.top();
        input.pop();

        while (!tempStack.empty() && tempStack.top() > temp)
        {
            input.push(tempStack.top());
            tempStack.pop();
        }
        tempStack.push(temp);
    }
    return tempStack;
}

int main()
{
    stack<int> input;
    input.push(34);
    input.push(3);
    input.push(31);
    input.push(98);
    input.push(92);
    input.push(23);
    input.push(5);
    input.push(0);
    stack<int> sortedStack = SortStack(input);
    cout << "sorted numbers are: " << endl;
    while (!sortedStack.empty())
    {
        cout << sortedStack.top() << " ";
        sortedStack.pop();
    }
    return 0;
}