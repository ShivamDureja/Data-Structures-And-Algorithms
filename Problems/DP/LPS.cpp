//Longest Palindromic subsequence
class Solution {
public:
    int lcs(string a,string b,int m,int n){
        int dp[m+1][n+1];
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
                else if(a[i-1] == b[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
    
    
    
    int longestPalindromeSubseq(string s) {
        string rev = s;
            reverse(rev.begin(),rev.end());
        int m = s.size();
        int n = rev.size();
        return lcs(s,rev,m,n);
    }
};