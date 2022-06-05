// You are given an integer array nums and an integer target.

// You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

// For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
// Return the number of different expressions that you can build, which evaluates to target.

#include<iostream> 
using namespace std;



int countSubsetSum(int arr[], int n, int sum){
    int dp[n+1][sum+1];
    for(int i=0;i<n+1;i++){
        dp[i][0] = 1;
    }
    for(int j = 0; j<sum + 1;j++){
        dp[0][j] = 0;
    }

    for(int i=1;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(arr[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
            }
        }
    }
    return dp[n][sum];
}


int targetSum(int arr[],int n,int target){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
    }
    if(target>sum || (sum + target) % 2 != 0){
        return 0;
    }
    sum = (target + sum) / 2;
    return countSubsetSum(arr,n,sum);
    
}



int main(){
    int arr[] = {1,1,1,1,1};
    int n = 5;
    int target = 3;
    cout<<targetSum(arr,n,target);
    return 0;
}