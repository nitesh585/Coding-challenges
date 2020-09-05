/*
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

Example:

Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note:  

    1 is typically treated as an ugly number.
    n does not exceed 1690.

*/

class Solution {
public:
    int nthUglyNumber(int n) {
        int i2 = 0;
        int i3 = 0;
        int i5 = 0;
        
        vector<int> ugly;
        ugly.emplace_back(1);
        
        int m = n;
        int two, three, five;
        while(n--){
            two = ugly[i2]*2;
            three = ugly[i3]*3;
            five = ugly[i5]*5;
            
            int curr = min( two, min(three , five) );
        
            ugly.emplace_back(curr);
            
            if(curr==two) i2++;
            if(curr==three) i3++;
            if(curr==five) i5++;
            
        }
        
        return ugly[m-1];
    }
};
