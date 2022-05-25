#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int LIS(int arr[],int n){
    int dp[n+1];
    int mx = 0;
// initialisation
    for(int i=0;i<n;i++){
        dp[i] = 1;
    }
    int ans = dp[0];


    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                dp[i] = max(dp[i], 1+dp[j]);
            }
        }
        ans = max(ans,dp[i]);
    }
    return ans;
}






int main(){
    int arr[] = {1,7,8,4,5,6,-1,9};
    int n = 8;
    int rslt = LIS(arr,n);
    cout<<rslt;
    return 0;
}