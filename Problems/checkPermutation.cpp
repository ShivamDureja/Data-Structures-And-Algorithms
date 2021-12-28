#include <iostream> //check if one string is permutation of the other
#include <bits/stdc++.h>
using namespace std;

bool chkPermutation(string str1, string str2)
{
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    for (int i = 0; i < str1.length(); i++)
    {

        if (str1[i] != str2[i])
        {
            return false;
        }
    }
    return true;
}

//Check palindrome of string
// bool chkPalindrome(string str){
//     for(int i=0;i<str.length();i++){
//         if(str[i] != str[str.length()-i-1]){
//             return false;
//         }
//     }
//     return true;

// }

int main()
{
    string s1 = "tat";
    string s2 = "tata";
    if (chkPermutation(s1, s2))
    {
        cout << "strings are permutation of one another";
    }
    else
    {
        cout << "strings are not permutation of one another";
    }
    return 0;
}