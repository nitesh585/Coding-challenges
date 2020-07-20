/*
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

class Solution {
public:
    
    void permutate(vector<int>& nums, int l, int r, vector<vector<int>>& ans){
        if(l==r){
            ans.push_back(nums);
        }else{
            for(int i=l; i<r; i++){
                swap(nums[l],nums[i]);
                
                permutate(nums, l+1, r, ans);
                
                swap(nums[l],nums[i]);
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> tmp;
        permutate(nums, 0, nums.size(), ans);
        
        return ans;
    }
};
