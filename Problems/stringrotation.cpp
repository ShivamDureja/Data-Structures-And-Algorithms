#include <iostream>
using namespace std;

bool isRotation(string s1, string s2)
{

    string temp = s1 + s1;
    return (temp.find(s2) != string::npos);  //string::npos used to indicate end of string
}

int main()
{
    string str1 = "shivam", str2 = "a";
    if (isRotation(str1, str2))
        printf("Strings are rotations of each other");
    else
        printf("Strings are not rotations of each other");
    return 0;
}