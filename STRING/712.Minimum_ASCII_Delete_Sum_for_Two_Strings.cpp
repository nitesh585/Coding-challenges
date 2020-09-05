/*
Given two strings s1, s2, find the lowest ASCII sum of deleted characters to make two strings equal.

Example 1:

Input: s1 = "sea", s2 = "eat"
Output: 231
Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
Deleting "t" from "eat" adds 116 to the sum.
At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.

Example 2:

Input: s1 = "delete", s2 = "leet"
Output: 403
Explanation: Deleting "dee" from "delete" to turn the string into "let",
adds 100[d]+101[e]+101[e] to the sum.  Deleting "e" from "leet" adds 101[e] to the sum.
At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.

Note:
0 < s1.length, s2.length <= 1000.
All elements of each string will have an ASCII value in [97, 122].
*/

class Solution {
public:
    /*
    Memoization ( Use cummutative sum instead of for loop in base case)
    int memo[1001][1001];
    
    int recursiveSol(string s1, string s2, int n1, int n2){
        if(n1==0){
            int sm=0;
            for(int i=0; i<n2; i++){
                sm+=(int)s2[i];
            }
             return sm;
        }
        
        if(n2==0){
            int sm=0;
            for(int i=0; i<n1; i++){
                sm+= (int)s1[i];
            }
            return sm;
        }
        
        if(s1[n1-1]==s2[n2-1]){
            return recursiveSol(s1, s2, n1-1, n2-1);
        }
        
        if(memo[n1][n2]!=-1){
            return memo[n1][n2];
        }
        
        return memo[n1][n2] =  min(recursiveSol(s1, s2, n1-1, n2) + (int)s1[n1-1] , 
                   recursiveSol(s1, s2, n1, n2-1) + (int)s2[n2-1]);
    }
    
    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        memset(memo, -1, sizeof(memo));
        
        return  recursiveSol(s1, s2, n1, n2);
    }
    */
    
    //Tabulation
    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        
        int dp[n1+1][n2+1];
        
        for(int i=0; i<=n1; i++){
            for(int j=0; j<=n2; j++){
                dp[i][j]=0;
            }
        }
        
        for(int i=n2-1; i>=0; --i){
            dp[n1][i] = dp[n1][i+1] + s2[i];
        }
        
        for(int i=n1-1; i>=0; --i){
            dp[i][n2] = dp[i+1][n2] + s1[i];
        }
        
        
        for(int i=n1-1; i>=0; --i){
            for(int j=n2-1; j>=0; --j){
                if(s1[i]==s2[j]){
                    dp[i][j] = dp[i+1][j+1];
                }else{
                    dp[i][j] = min(dp[i][j+1] + s2[j], dp[i+1][j] + s1[i]);
                }
                
            }
        }
        
        return  dp[0][0];
    }
};
