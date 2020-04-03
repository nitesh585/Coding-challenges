/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        int i=0;
        vector<int> res;
        for(auto a = nums.begin();a!=nums.end();a++,i++){
            if(m.find(target - (*a))!=m.end()){
               res.push_back(m[target - (*a)]);
               res.push_back(i);
            }else{
              m[*a]=i;   
            }
        }
        
        return res;
    }
};
