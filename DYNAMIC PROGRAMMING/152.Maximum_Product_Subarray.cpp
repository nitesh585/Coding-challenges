/*
Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

*/

class Solution {
public:
    
    int maxProduct(vector<int>& nums) {
        if(nums.size()==0){
            return -1;
        }
        
        int currMax = nums[0];
        int currMin = nums[0];
        int finalMax = nums[0];
        
        for(int  i=1; i<nums.size(); i++){
            int tmp = currMax;
            currMax = max(max(currMax*nums[i] , currMin*nums[i]), nums[i]);
            currMin = min(min(tmp*nums[i] , currMin*nums[i]), nums[i]);
            
            finalMax = max(finalMax, currMax);
        }
        
        return finalMax;
    }
};











