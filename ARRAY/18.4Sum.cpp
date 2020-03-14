/*
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.
*/

class Solution {
public:
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin() , nums.end());
        if(n>3){
            
            for(int i=0;i<n-3;i++){
                if( nums[i]+nums[i+1]+nums[i+2]+nums[i+3] > target ) break;
                if( nums[i]+nums[n-1]+nums[n-2]+nums[n-3] < target ) continue;
                if(i>0 && nums[i]==nums[i-1]) continue; //handling duplicates
                
                for(int j=i+1; j<n-2; j++){
                    if( nums[i]+nums[j]+nums[j+1]+nums[j+2] > target ) break;
                    if( nums[i]+nums[j]+nums[n-1]+nums[n-2] < target ) continue;
                     
                    if(j>i+1 && nums[j]==nums[j-1]) continue; //handling duplicates
                    
                    int left = j+1, right = n-1;
                    while(left<right){
                        int sum = nums[i]+nums[j]+nums[left]+nums[right] ; 
                        if(sum==target){
                            ans.push_back({nums[i],nums[j],nums[left],nums[right]});
                            int left_element = nums[left] , right_element = nums[right];
                            
                            while(left<right && nums[left]==left_element) left++;
                            while(left<right && nums[right]==right_element) right--;
                        }else if(sum<target){
                            left++;
                        }else{
                            right--;
                        }
                        
                    }
                    
                }
                
            }
            
            
        }
        
        return ans;
    }    
};

