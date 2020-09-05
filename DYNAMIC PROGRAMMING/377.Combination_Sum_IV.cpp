/*
Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.

*/

class Solution {
public:
    
    int helper(vector<int>& nums, int target, int dp[]){
        if(target==0){
            return 1;
        }
        
        if(target<0){
            return 0;
        }
        
        if(dp[target]!=-1){
            return dp[target];
        }
        
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            ans+=helper(nums, target-nums[i], dp);
        }
        
        return dp[target] = ans;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        int dp[target+1];
        memset(dp, -1, sizeof(dp));
        return helper( nums, target, dp);
    }
};
