/*
Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

Example 1:

Input: 4
Output: 2

Example 2:

Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since 
             the decimal part is truncated, 2 is returned.


*/
class Solution {
public:
    
    
    int mySqrt(int x) {
        if(x<2){
            return x;
        }
        
        int low = 0;
        int high = x;
        
        while(low<high){
            long long int mid = low + (high-low)/2;
            
            if(mid*mid == x){
                return mid;
            }
            
            if(mid*mid > x){
                high = mid;
            }else if(mid*mid < x){
                low = mid+1;
            }
        }
        
        return low-1;
    }
};
