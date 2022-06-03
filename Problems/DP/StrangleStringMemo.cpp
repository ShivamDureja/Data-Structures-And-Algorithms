/*We can scramble a string s to get a string t using the following algorithm:

If the length of the string is 1, stop.
If the length of the string is > 1, do the following:
Split the string into two non-empty substrings at a random index, i.e., if the string is s, divide it to x and y where s = x + y.
Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, s may become s = x + y or s = y + x.
Apply step 1 recursively on each of the two substrings x and y.
Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, otherwise, return false. */

// Memoized Version using unordered map

#include <iostream>
#include <cstring>
#include <iterator>
#include <unordered_map>
using namespace std;

unordered_map<string, bool> mp;

bool solve(string a, string b)
{
    int n = a.length();
    if (a.compare(b) == 0)
    {
        return true;
    }
    if (a.length() <= 1)
    {
        return false;
    }
    string key = (a + " " + b);
    if (mp.find(key) != mp.end())
    {
        return mp[key];
    }
    bool flag = false;
    for (int i = 1; i < n; i++)
    {
        if (solve(a.substr(0, i), b.substr(n - i, i)) && solve(a.substr(i, n - i), b.substr(0, n - i)))
        {
            flag = true;
            return true;
        }
        if (solve(a.substr(0, i), b.substr(0, i)) && solve(a.substr(i, n - i), b.substr(i, n - i)))
        {
            flag = true;
            return true;
        }
    }
    mp[key] = flag;
    return false;
}

int main()
{
    string a = "coder";
    string b = "ocred";
    if (a.length() != b.length())
    {
        return false;
    }
    bool ans = solve(a, b);
    if (ans == true)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}


