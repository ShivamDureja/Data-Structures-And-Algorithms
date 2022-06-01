// Recursive Memoized

class Solution {
public:
    int dp[2001][2001];
    bool isPalindrome(string &s,int start,int end){
        while(start < end){
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    
    
    
    
    int solve(string &s, int i, int j){
        if(i >= j){
            return 0;
        }
        if(isPalindrome(s,i,j)){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int mini = INT_MAX;
        for(int k=i;k<=j-1;k++){
            
            if(isPalindrome(s,i,k)){
              int temp = solve(s,i,k) + solve(s,k+1,j) + 1;
            if(temp < mini){
                mini = temp;
            }  
            }
            
        }
        return dp[i][j] = mini;
    }
    
    
    
    int minCut(string s) {
        memset(dp,-1,sizeof(dp));
        int n = s.length();
        return solve(s,0,n-1);
    }
};