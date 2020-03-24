/*
Balanced strings are those who have equal quantity of 'L' and 'R' characters.

Given a balanced string s split it in the maximum amount of balanced strings.

Return the maximum amount of splitted balanced strings.

 

Example 1:

Input: s = "RLRRLLRLRL"
Output: 4
Explanation: s can be split into "RL", "RRLL", "RL", "RL", each substring contains same number of 'L' and 'R'.
*/

class Solution {
public:
    int balancedStringSplit(string s) {
        short cntl=0, cntr=0;
        short ans=0;
        for(int i=0; i<s.length() ; i++){
            if(s[i]=='L') cntl++;
            if(s[i]=='R') cntr++;
            
            if(cntl==cntr){
                ans++;
                cntl=0;
                cntr=0;
            }
        }
        return ans;
    }
};
