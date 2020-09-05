/*
 Given two words word1 and word2, find the minimum number of steps required to make word1 and word2 the same, where in each step you can delete one character in either string.

Example 1:

Input: "sea", "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".

Note:

    The length of given words won't exceed 500.
    Characters in given words can only be lower-case letters.
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        
        int dp[n1+1][n2+1];
        for(int i=0; i<=n1; ++i){
            for(int j=0; j<=n2; ++j){
                dp[i][j]=0;
            }
        }
        
        for(int i=0; i<=n1; ++i){
            dp[i][0] = i;
        }
        
        for(int i=0; i<=n2; ++i){
            dp[0][i] = i;
        }
        
        for(int i=1; i<=n1; ++i){
            for(int j=1; j<=n2; ++j){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = min(dp[i-1][j] , dp[i][j-1]) + 1;
                }
            }
        }
        
        return dp[n1][n2];
    }
};
