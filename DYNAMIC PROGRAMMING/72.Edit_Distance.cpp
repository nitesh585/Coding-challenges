/*
Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

    Insert a character
    Delete a character
    Replace a character

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
*/


class Solution {
public:
  
    int minimum(int a, int b, int c){
        return min(min(a,b),c);
    }
    
    int recursive(string word1, string word2, int n1, int n2){
        if(n1==0){
            return n2;
        }
        
        if(n2==0){
            return n1;
        }
        
        if(word1[n1-1]==word2[n2-1]){
            return recursive(word1, word2, n1-1, n2-1);
        }
        
        return minimum( recursive(word1, word2, n1-1, n2-1),
                        recursive(word1, word2, n1-1, n2),
                        recursive(word1, word2, n1, n2-1) ) + 1;
    }
    
    int minDistance(string word1, string word2) {
        int n1 = word1.size() , n2=word2.size();
        int dp[n1+1][n2+1];
        
        for(int i=0; i<=n1; i++){
            dp[i][0] = i;
        }
        
        for(int i=0; i<=n2; i++){
            dp[0][i] = i;
        }
        
        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = 1 + minimum( dp[i-1][j-1] ,
                                            dp[i-1][j] , 
                                            dp[i][j-1]) ;
                }
            }
        }
        
        return dp[n1][n2];   
    }
};
