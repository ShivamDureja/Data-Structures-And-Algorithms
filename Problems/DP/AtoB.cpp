// Minimum number of insertion and deletion to conert string a to b
#include<iostream>
#include<algorithm>
using namespace std;


int Lcs(string a,string b,int m,int n){
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a.at(i-1) == b.at(j-1)){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else{
                dp[i][j] = std::max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[m][n]; 
}




int main(){
    string a = "heap";
    string b = "pea";
    
    int m = a.size();
    int n = b.size();
    int len = Lcs(a,b,m,n);
    int ins = n-len;
    cout<<"Minimum number of insertions  "<<ins<<endl;
    cout<<"Minimum number of deletions  "<<m-len;
    return 0;
}