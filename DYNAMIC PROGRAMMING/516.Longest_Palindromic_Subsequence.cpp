/*
Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

Example 1:
Input:

"bbbab"

Output:

4

One possible longest palindromic subsequence is "bbbb".

 

Example 2:
Input:

"cbbd"

Output:

2

One possible longest palindromic subsequence is "bb".

 

Constraints:

    1 <= s.length <= 1000
    s consists only of lowercase English letters.


*/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
        int n = s.length();
        string rev = s;
        
        reverse(s.begin(),s.end());
        
        int dp[n+1][n+1];
        
        for(int i=0; i<=n; i++){
            for(int j=0; j<=n; j++){
                if(i==0 || j==0){
                    dp[i][j] = 0;
                }else if(s[i-1]==rev[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
        
        return dp[n][n];
    }
};
