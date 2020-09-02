/*
Given two sorted arrays nums1 and nums2 of size m and n respectively.

Return the median of the two sorted arrays.

Follow up: The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

Example 3:

Input: nums1 = [0,0], nums2 = [0,0]
Output: 0.00000

Example 4:

Input: nums1 = [], nums2 = [1]
Output: 1.00000

Example 5:

Input: nums1 = [2], nums2 = []
Output: 2.00000

 

Constraints:

    nums1,length == m
    nums2,length == n
    0 <= m <= 1000
    0 <= n <= 1000
    1 <= m + n <= 2000


*/
class Solution {
public:
       
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        
        if(m > n){
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int lo =0;
        int hi = m;
        int halfLen = (n+m+1)/2;
        
        int leftX, rightX, leftY, rightY;
        
        while(lo <= hi){
            int i = (hi+lo)/2;
            int j = halfLen - i;
            
            leftX =  i==0 ? INT_MIN : nums1[i-1];
            rightX = i==m ? INT_MAX : nums1[i];
            
            leftY =  j==0 ? INT_MIN : nums2[j-1];
            rightY = j==n ? INT_MAX : nums2[j];
            
            if(leftX <= rightY && leftY <= rightX){
                if( (n+m)%2==0 ){
                    return (max(leftX, leftY) + min(rightX, rightY))/2.0;
                }else{
                    return max(leftX, leftY);
                }
            }
            
            if(leftX > rightY){
                hi = i-1;
            }else{
                lo = i+1;
            }
            
        }
        
        return -1;
    }
}; 
