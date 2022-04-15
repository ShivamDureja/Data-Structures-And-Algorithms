#include<iostream>
using namespace std;


bool isSubsetSum(int set[],int n,int sum){

    bool subset[n+1][sum+1];
    //initialisation
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(i == 0)
                subset[i][j] = false;
            if(j == 0)
                subset[i][j] = true;
        }
    }
    //left over code
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(set[i-1]<=j){
                subset[i][j] = subset[i-1][j-set[i-1]] || subset[i-1][j];
            }
            if(j<set[i-1]){
                subset[i][j] = subset[i-1][j];
            }
        }
    }
    return subset[n][sum];


}


int main(){
    int set[] = {2,3,7,8,10};
    int sum = 14;
    int n = sizeof(set)/sizeof(set[0]);
    if(isSubsetSum(set,n,sum) == true)
        cout<<"Found";
    else
        cout<<"Not Found";

    return 0;
}