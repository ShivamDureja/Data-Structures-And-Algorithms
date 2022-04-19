#include<iostream>
using namespace std;

int minDiff(int arr[],int n){
    //calculate the sum
    int sum = 0,res = 0,ans = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
    }
    res = sum;
    //divide sum by 2
    if(sum%2 == 0){
        sum = sum/2;
    }
    else{
        sum = (sum+1)/2;
    }

    //create dp
    bool dp[n+1][sum+1];
    //initialize dp
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(i == 0)
                dp[i][j] = false;
            if(j==0)
                dp[i][j] = true;
        }
    }

    //calculating each state
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1]<j){
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }if(arr[i-1]>j){
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    //run loop in last col and return total sum i.e range-2j
    for(int i=sum;i>=0;i--){
        if(dp[n][i]){
            ans = abs(res-2*i);
            break;
        }
    }

    return ans;


}



int main(){
    int arr[] = { 3, 1, 4, 2, 2, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The minimum difference between 2 sets is "
         << minDiff(arr, n);
    return 0;
    
}