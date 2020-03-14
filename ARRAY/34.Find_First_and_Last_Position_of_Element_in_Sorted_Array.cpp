/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].
*/

class Solution {
public:
    int i=-1,j=-1;
    
    void binary_search(vector<int>& nums , int target,int l, int r,bool left){
    
       if(r>=l){    
        int mid =  l+(r-l)/2;
        if(left && (target == nums[mid])){
            i = mid;
        }
        
        if(!left && (target == nums[mid])){
            j = mid;
        }
           
        if(left){
        if(target<=nums[mid]){
            binary_search(nums,target,l,mid-1,left);
        }else{
            binary_search(nums,target,mid+1,r,left);
         }
        }else{
           if(target<nums[mid]){
            binary_search(nums,target,l,mid-1,left);
        }else{
            binary_search(nums,target,mid+1,r,left);
         }  
        }
       }
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        binary_search(nums,target,0,nums.size()-1,true);
        binary_search(nums,target,0,nums.size()-1,false);
        
        vector<int> ans = {i,j};
        return ans;
    }
};
