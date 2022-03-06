//Find all permutations of the given array 
//Without using any extra space
// T.C-> n! * n
#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public: 
        void recurPermute(int index,vector<int> &nums,vector<vector<int>> &ans){
            //base case  
            if(index == nums.size()){
                    ans.push_back(nums);
                    return;
            }
            //recursive call
            for(int i=index;i<nums.size();i++){
                swap(nums[index],nums[i]);
                recurPermute(index+1,nums,ans);
                swap(nums[index],nums[i]);
            }
        }

    public: 
        vector<vector<int>> permute(vector<int> & nums){
            vector<vector<int>> ans;
            recurPermute(0,nums,ans);
            return ans;
        }
};