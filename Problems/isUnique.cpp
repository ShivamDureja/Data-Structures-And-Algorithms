#include <iostream>
using namespace std;

bool isUnique(string, int);

int main()
{
    bool uniq;
    string a;
    cout << "Enter ur string!!" << endl;
    getline(cin, a);
    uniq = isUnique(a, a.length());
    if (uniq == true)
    {
        cout << "The string has no repetations." << endl;
    }
    else
    {
        cout << "The characters in the string are not unique." << endl;
    }
    return EXIT_SUCCESS;
}

bool isUnique(string str, int len)
{
    bool uniq = true;
    for (int i = 0; i < len - 1; ++i)
    {
        for (int j = i + 1; j < len; ++j)
        {
            if (str[j] == str[i])
            {
                uniq = false;
            }
        }
    }
    return uniq;
}
