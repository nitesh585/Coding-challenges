/*
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example 1:

Input: a = 1, b = 2
Output: 3
*/

class Solution {
public:
    int getSum(int a, int b) {
        int carry=0;
        if(b>a){
            b=a+b;
            a = b-a;
            b = b-a;
        }
        while(b){
           int sum = a^b;
           b =(unsigned int)(a&b)<<1;
           a = sum;      
        }
        
        return a;
    }
};
