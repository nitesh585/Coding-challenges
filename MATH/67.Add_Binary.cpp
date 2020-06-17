/*
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"

Example 2:

Input: a = "1010", b = "1011"
Output: "10101"

 

Constraints:

    Each string consists only of '0' or '1' characters.
    1 <= a.length, b.length <= 10^4
    Each string is either "0" or doesn't contain any leading zero.


*/

class Solution {
public:
    string addBinary(string a, string b) {
        int carry=0,sum=0;
        int i = a.length()-1, j = b.length()-1;
        string res="";
        while(i>=0 && j>=0){
            sum = a[i] + b[j] +carry - 96;
            carry = sum/2;
            sum%=2;
            res = to_string(sum)+res;
            i--;
            j--;
        }
       while(i>=0){
           sum = a[i]+carry-48;
           carry = sum/2;
           sum%=2;
           res = to_string(sum)+res;
           i--;
       }
       
       while(j>=0){
           sum = b[j]+carry-48;
           carry = sum/2;
           sum%=2;
           res = to_string(sum)+res;
           j--;
       }
       if(carry>0){
           res = to_string(carry)+res;
       }
       return res;
        
    }
};
