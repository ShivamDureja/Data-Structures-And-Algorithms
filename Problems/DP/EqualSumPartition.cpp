#include<iostream>
#include<vector>
using namespace std;

 bool subsetSum(vector<int> nums,int sum){
        int n = nums.size();
        bool subset[n+1][sum+1];
        for (int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(i == 0)
                    subset[i][j] = false;
                if(j == 0)
                    subset[i][j] = true;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(j<nums[i-1]){
                    subset[i][j] = subset[i-1][j];
                }
                else if(j>=nums[i-1]){
                    subset[i][j] = subset[i-1][j-nums[i-1]] || subset[i-1][j];
                }
            }
        }
        return subset[n][sum];
    }

    bool canPartition(vector<int>& nums) {
      int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum = sum + nums[i];
        }
        if(sum%2 != 0)
            return false;
        else
            return subsetSum(nums,sum/2);
        
    }



int main(){
    
    vector<int> set = {1,5,5,11};
    
    
    if(canPartition(set) == true)
        cout<<"Found";
    else
        cout<<"Not Found";
    return 0;
}