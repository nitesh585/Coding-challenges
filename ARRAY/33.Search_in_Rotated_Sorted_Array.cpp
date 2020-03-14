/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).
*/

class Solution {
public:
    int binary_search(vector<int>& nums,int start,int end,int val ){
        int mid = start + (end - start) / 2; 
        if(start>end){
            return -1;
        }
        if(nums[mid]==val){
            return mid;
        }
        if(nums[mid]<val){
           return binary_search(nums,mid+1,end,val);
        }else{
           return binary_search(nums,start,mid-1,val);
        }
    }
    
    int search(vector<int>& nums, int target) {
        if(nums.empty()){
            return -1;
        }
        int s2 = 0,e1 = nums.size()-1;
        for(auto i = nums.begin(); i!=nums.end()-1; i++){
            if(*i > *(i+1) ){
                e1 =  i - nums.begin();
                s2 = e1+1;
                break;
            }
        }
        cout<<e1<<" "<<s2<<endl;
        if((target >= nums[0])  && (target <= nums[e1]) ){
            return binary_search(nums,0,e1,target);
        }else{
            return binary_search(nums,s2,nums.size()-1,target);
        }
    }
};
