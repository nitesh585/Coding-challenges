/*
Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two’s complement method is used. 
Note:

    All letters in hexadecimal (a-f) must be in lowercase.
    The hexadecimal string must not contain extra leading 0s. If the number is zero, it is represented by a single zero character '0'; otherwise, the first character in the hexadecimal string will not be the zero character.
    The given number is guaranteed to fit within the range of a 32-bit signed integer.
    You must not use any method provided by the library which converts/formats the number to hex directly.

Example 1:

Input:
26

Output:
"1a"

Example 2:

Input:
-1

Output:
"ffffffff"

*/

class Solution {
public:
    string toHex(int num) {
        if(!num){
            return "0";
        }
        string map = "0123456789abcdef";
        string res="";
        unsigned int  n = num;
        while(n){
            res=(map[n&15])+res;
            n>>=4;
        }
        return res;
    }
};
