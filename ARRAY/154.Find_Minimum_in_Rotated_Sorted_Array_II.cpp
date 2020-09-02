/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

The array may contain duplicates.

Example 1:

Input: [1,3,5]
Output: 1

Example 2:

Input: [2,2,2,0,1]
Output: 0
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==0){
            return -1;
        }
        
        int low = 0;
        int high = nums.size()-1;
        
        while(low<high){
            
            int mid = low + (high-low)/2;
            
            if(nums[high] == nums[mid] ){
                high--;
            }else if( nums[mid] > nums[high] ){
                low = mid+1;
            }else{
                high = mid;
            }
        }
        
        return nums[low];
    }
};
