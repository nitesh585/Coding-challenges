/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Example 1:

Input: [3,0,1]
Output: 2

Example 2:

Input: [9,6,4,2,3,5,7,0,1]
Output: 8

*/

// Using sum method
class Solution {
public:
    int missingNumber(vector<int>& nums) {
      int sum=0;
      int n = nums.size();
      for(int i=0;i<nums.size();i++){
          sum+=nums[i];
      }
        return ((n*(n+1)/2) - sum);
    }
};


// Xor method
class Solution {
public:
    int missingNumber(vector<int>& nums) {
      int ans=0;
      for(int i=0;i<nums.size();i++){
        ans^=nums[i];
        ans^=(i+1);
      }
        return ans;
    }
};
