/*
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example 1:

Input: 16
Output: true
*/

class Solution {
public:
    bool isPowerOfFour(int n) {
        int cnt=0,pos=0;
        for(int i=0;i<32;i++){
            if(n&(1<<i)){
                cnt++;
                pos=i;
            }
        }
        return (cnt==1) && (pos%2==0)?true:false;;
    }
};


//Without loop
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==0 || n==-2147483648 ) return false;
        if(n && n&(n-1)) return false;  // more than one set bit

        return ( (int)log2(n) )%2 == 0;   //position of set bit should be even
    }
};

