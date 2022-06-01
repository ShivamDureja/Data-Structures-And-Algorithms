#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int dp[100][100];
int solve(int arr[], int i, int j)
{
    if (i >= j)
    {
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int mini = INT_MAX;
    for(int k = i;k<j;k++){
        int temp = solve(arr,i,k) + solve(arr,k+1,j) + arr[i-1] * arr[k] * arr[j];
        if(temp < mini){
            mini = temp;
        }
    }
    return mini;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int i = 1;
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int j = n - 1;
    cout<<"MCM is" << endl;
    cout<<solve(arr,i,j);
    return 0;
}