/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

Example:

Input:  [1,2,1,3,2,5]
Output: [3,5]
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xr=0;
	  // xr is a^b ( xor of the required two numbers)
        for(int i=0;i<nums.size();i++){
            xr^=nums[i];
        }
        xr&=~(xr-1); // finding the last set bit
        vector<int> res ={0,0};
        
	  // on the basis of lastset bit group the two numbers
        for(int i=0;i<nums.size();i++){
           if(xr&nums[i]){
               res[0]^=nums[i];
           }else{
               res[1]^=nums[i];
           }
        }
        return res;
    }
};
