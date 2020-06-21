/*
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

Example:

Input: 38
Output: 2 
Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2. 
             Since 2 has only one digit, return it.

*/

class Solution {
public:
    int addDigits(int num) {
        while((num/10)!=0){
            int x=num,sum=0;
            while(x!=0){
                sum+=(x%10);
                x/=10;
            }
            num=sum;
        }
        return num;
    }
};
