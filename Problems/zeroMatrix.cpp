/* Write an algorithm such that if any element in a matrix is found as 0,
   the entire row and col are set to zero*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void setMatrixZero(vector<vector<int>> a)
{
    int n = a.size();
    int m = a[0].size();
    set<int> row;
    set<int> column;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 0)
            {
                row.insert(i);
                column.insert(j);
            }
        }
    }
    for (auto r : row)
    {
        for (int j = 0; j < m; j++)
        {
            a[r][j] = 0;
        }
    }
    for (auto c : column)
    {
        for (int j = 0; j < n; j++)
        {
            a[j][c] = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> a = {{1, 0, 1}, {1, 1, 1}, {1, 5, 1}};
    setMatrixZero(a);
    return 0;
}