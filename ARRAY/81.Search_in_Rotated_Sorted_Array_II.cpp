/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

You are given a target value to search. If found in the array return true, otherwise return false.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true

Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
*/

class Solution {
public:
    
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        
        while(low <= high){
            
            int mid = low + (high-low)/2;
            if(nums[low]==target || nums[high]==target || nums[mid]==target){
                return true;
            }
            
            if(nums[low] < nums[mid]){
                
                if( nums[low] < target && target < nums[mid] ){
                    high = mid-1;                    
                }else{
                    low = mid+1;
                }
                
            }else if(nums[mid] < nums[high]){
                
                if( nums[mid] < target && target < nums[high] ){
                    low = mid+1;                    
                }else{
                    high = mid-1;
                }
                
            }else{
                low++;
            }
            
        }
        
        return false;
    }
};
