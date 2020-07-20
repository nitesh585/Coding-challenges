3/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

*/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> lists;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
        
            int low = i+1, high=n-1;
            while(low<high){
                
                if((nums[i]+nums[low]+nums[high])==0){
                    lists.push_back({nums[i],nums[low],nums[high] });
                    
                    while(low<high && nums[low]==nums[low+1] ) low++;
                    while(low<high && nums[high]==nums[high-1] ) high--;
                    
                    low++; high--;
                    
                }else if((nums[i]+nums[low]+nums[high])<0) low++;
                else high--;
                
            }
        }
        
        return lists;
    }
};
