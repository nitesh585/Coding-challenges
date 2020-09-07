/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6

*/

class Solution {
public:
    int trap(vector<int>& height) {
        /*
        
        Time  -  O(n)
        Space -  O(n)

        int sum=0;
        vector<int> left(n);
        vector<int> right(n);
        
        left[0] = heights[0];
        right[n-1] = heights[n-1];
        
        // left maximums
        for(int i=1; i<n; i++){
            left[i] = max(left[i-1], heights[i]);
        }
        
        // right maximums
        for(int i=n-2; i>=0; i--){
            right[i] = max(right[i+1], heights[i]);
        }
        
        for(int i=1; i<n-1; i++){    
            sum+=(min(left[i], right[i]) - heights[i]); 
        }
        
        */
        
        int n = height.size();
        if(n==0){
            return 0;
        }
        
        int ans=0;
        int left = 0;
        int right  = n-1;
        int lmax = height[left];
        int rmax = height[right];
        
        while(left<right){
            
            if(height[left] < height[right]){
                if(lmax <= height[left]){
                    lmax =  height[left];
                }else{
                    ans+=(lmax - height[left]);
                }
                left++;
            }else{
                if(rmax <= height[right]){
                    rmax =  height[right];
                }else{
                    ans+=(rmax - height[right]);
                }
                right--;
            }
        }
        
        return ans;
    }
};
