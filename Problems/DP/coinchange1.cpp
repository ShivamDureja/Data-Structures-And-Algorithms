#include<iostream>
using namespace std;

int coinchange(int coins[],int n,int sum){
    int t[n+1][sum+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(i==0){
                t[i][j] = 0;
            }
            else if(j==0){
                t[i][j] = 1;
            }
            else if(coins[i-1]>j){
                t[i][j] = t[i-1][j];
            }
            else{
                t[i][j] = t[i][j-coins[i-1]] + t[i-1][j];
            }
        }
    }

    
    return t[n][sum];

}








int main(){
    int coins[] = {1,2,3};
    int sum = 4;
    int n = sizeof(coins)/sizeof(coins[0]);
    cout<<coinchange(coins,n,sum);
    return 0;
}