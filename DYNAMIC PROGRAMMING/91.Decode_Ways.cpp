/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26

Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).

Example 2:

Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).


*/

class Solution{
public:
    
    /*
    
    int helper(string s, int i,int n){
        
        if(i==n){
            return 1;
        }
        if(i>n){
            return 0;
        }
        int one = 0;
        
        if(s[i] > '0'){
            one = helper(s, i+1, n);
        }

        int two = 0;
        
        if( (s.size()>1) && (s[i] > '0') ){
            string twoDigit = "";
            
            twoDigit+=s[i];
            twoDigit+=s[i+1];
            
            if( stoi(twoDigit) <= 26 ){
                two  = helper(s, i+2, n);
            }    
        }
        
        return one + two;
    }
    
    */
    
    int numDecodings(string s) {
        int n = s.size();
        int dp[n+1];
        
        memset(dp, 0, sizeof(dp));
        
        dp[0] = 1;
        dp[1] = 1;
        
        if(s[0]=='0'){
           return 0;  
        } 
        
        for(int i=2; i<=n; i++){
            if(s[i-1] > '0'){
                dp[i] = dp[i-1];
            }
            if(s[i-2]=='1' || s[i-2]=='2' && s[i-1] <='6' ){
                dp[i] += dp[i-2];
            }
        }
        
        return dp[n];
    }
};
