/*
Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into k non-empty subsets whose sums are all equal.

 

Example 1:

Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
Output: True
Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.

Note:

    1 <= k <= len(nums) <= 16.
    0 < nums[i] < 10000.
*/

class Solution {
public:
    
    bool helper(vector<int>& nums, vector<bool>& used, int target, int sum, int k, int idx){
        if(k==0){
            return true;
        }
        
        if(sum>target){
            return false;
        }
        
        if(sum==target){
            return helper(nums, used, target, 0, k-1, 0);
        }
        
        for(int i = idx; i<nums.size(); i++){
            if(!used[i]){
                used[i] = true;
                
                if(helper(nums, used, target, sum+nums[i] , k, i)){
                    return true;
                }
                
                used[i] = false;
            }
        }
        
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        vector<bool> used(n);
        
        int target=0;
        for(int i=0; i<n; i++){
            target+=nums[i];
            used[i] = false;
        }
        
        if(target%k!=0){
            return false;
        }
        
        return helper(nums, used, target/k ,0, k, 0);
    }
};
