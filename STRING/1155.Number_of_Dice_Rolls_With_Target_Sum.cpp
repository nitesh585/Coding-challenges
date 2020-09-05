/*
You have d dice, and each die has f faces numbered 1, 2, ..., f.

Return the number of possible ways (out of fd total ways) modulo 10^9 + 7 to roll the dice so the sum of the face up numbers equals target.

 

Example 1:

Input: d = 1, f = 6, target = 3
Output: 1
Explanation: 
You throw one die with 6 faces.  There is only one way to get a sum of 3.

Example 2:

Input: d = 2, f = 6, target = 7
Output: 6
Explanation: 
You throw two dice, each with 6 faces.  There are 6 ways to get a sum of 7:
1+6, 2+5, 3+4, 4+3, 5+2, 6+1.

Example 3:

Input: d = 2, f = 5, target = 10
Output: 1
Explanation: 
You throw two dice, each with 5 faces.  There is only one way to get a sum of 10: 5+5.

Example 4:

Input: d = 1, f = 2, target = 3
Output: 0
Explanation: 
You throw one die with 2 faces.  There is no way to get a sum of 3.

Example 5:

Input: d = 30, f = 30, target = 500
Output: 222616187
Explanation: 
The answer must be returned modulo 10^9 + 7.

 

Constraints:

    1 <= d, f <= 30
    1 <= target <= 1000

*/

class Solution {
public:
    int dp[31][1001];
    
    int rollsToTarget(int target, int f, int d){
        if( d==0 && target==0){
            return 1;
        }
        
        if(d==0 || target==0){
            return 0;
        }
        
        if(dp[d][target]!=-1){
            return dp[d][target];
        }
    
        int ans = 0;
        for(int i=1; i<=f; i++){
            if(target>=i){
                ans =(ans%1000000007 + rollsToTarget(target - i, f, d-1)%1000000007)%1000000007;
            }
        }
        
        return dp[d][target] = ans;
    }
    
    int numRollsToTarget(int d, int f, int target) {
        
        memset(dp,-1, sizeof(dp));
        
        return rollsToTarget(target, f, d);
    }
};
