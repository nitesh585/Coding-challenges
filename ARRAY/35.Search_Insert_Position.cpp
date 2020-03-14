/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty()){
            return 0;
        }
        int res = nums.size();
        for(auto i=nums.begin(); i!=nums.end() ; i++){
            if( (*i==target) || (*i > target) ){
                return (i-nums.begin());
            }
            
        }
        return res;
    }
};
