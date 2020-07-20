/*
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]


*/

class Solution {
public:
    vector<int>  subset(vector<int> nums,int k){
        vector<int> res;
        int i=0;
        while(k){
            if(k&1){
                res.push_back(nums[i]);
            }
            i++;
            k = k>>1;
        }
        
        return res;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        for(int i=0;i<pow(2,n);i++){
            vector<int> tmp = subset(nums,i);
            res.push_back(tmp);
        }
        
        return res;
    }
};
