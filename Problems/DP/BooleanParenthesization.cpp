// Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.
// recursive approach  
//Hard Problem
#include <iostream>
using namespace std;

int solve(string s, int i, int j, int isTrue)
{
    if (i > j)
    {
        return 0;
    }
    if (i == j)
    {
        if (isTrue)
        {
            return s[i] == 'T';
        }
        else
        {
            return s[i] == 'F';
        }
    }
    int ans = 0;
    for (int k = i + 1; k <= j - 1; k = k + 2)
    {
        int lf = solve(s, i, k - 1, 0);
        int lt = solve(s, i, k - 1, 1);
        int rt = solve(s, k + 1, j, 1);
        int rf = solve(s, k + 1, j, 0);

        // Calculating ans from temp answers
        if (s[k] == '&')
        {
            if (isTrue)
            {
                ans = ans + lt * rt;
            }
            else
            {
                ans = ans + lf * rf + lf * rt + lt * rf;
            }
        }

        else if (s[k] == '|')
        {
            if (isTrue)
            {
                ans = ans + lt * rt + lf * rt + lt * rf;
            }
            else
            {
                ans = ans + lf * rf;
            }
        }
        else if (s[k] == '^')
        {
            if (isTrue)
            {
                ans = ans + lf * rt + lt * rf;
            }
            else
            {
                ans = ans + lf * rf + lt * rt;
            }
        }
    }
    return ans;
}

int main()
{
    string s = "T|T&F^T";
    int i = 0;
    int j = s.length() - 1;
    int res = solve(s, i, j, 1);
    cout << res;

    return 0;
}