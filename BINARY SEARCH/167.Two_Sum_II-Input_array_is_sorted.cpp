/*
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

Note:

    Your returned answers (both index1 and index2) are not zero-based.
    You may assume that each input would have exactly one solution and you may not use the same element twice.

Example:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.


*/

class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        vector<int> res;
        
        int low = 0, high = num.size()-1;
        while(low<=high){
            if((num[low]+num[high]) == target){
                return {low+1,high+1};   
            }else if((num[low]+num[high]) < target){
                low++;
            }else{
                high--;
            }
        }
        
        return res;
    }
};
