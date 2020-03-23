/*
Given an integer, write a function to determine if it is a power of two.

Example 1:

Input: 1
Output: true 
Explanation: 2^0 = 1

Example 2:

Input: 16
Output: true
Explanation: 2^4 = 16
*/

// Simple Solution:
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1){
            return true;
        }
        if(n<=0){
            return false;
        }
        while(n>1){
            if(n%2!=0){
                return false;
            }
            n/=2;
        }
        return true;
    }
};


// Trick ( Check there is only one set bit )
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        
        return (n && !(n&(n-1)));
    }
};
