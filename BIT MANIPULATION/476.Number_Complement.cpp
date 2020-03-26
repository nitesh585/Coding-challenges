/*
Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

Example 1:

Input: 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.

*/

class Solution {
public:
    int findComplement(int num) {
        int res=0;
        while(num>0){
            num<<=1;
            res++;
        }
        return (~num)>>(res);
    }
};
