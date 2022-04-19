#include <iostream>
using namespace std;

int countDiff(int arr[], int n, int diff)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int s2 = (sum - diff) / 2;
    int dp[n + 1][s2 + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s2; j++)
        {
            if (i == 0)
                dp[i][j] = 0;
            if (j == 0)
                dp[i][j] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= s2; j++)
        {
            if (arr[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
            }
        }
    }
    return dp[n][s2];
}

int main()
{
    int set[] = {1, 1, 2, 3};
    int diff = 1;
    int n = sizeof(set) / sizeof(set[0]);
    cout << countDiff(set, n, diff);

    return 0;
}