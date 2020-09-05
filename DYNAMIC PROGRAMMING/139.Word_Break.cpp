/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

    The same word in the dictionary may be reused multiple times in the segmentation.
    You may assume the dictionary does not contain duplicate words.

Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.

Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false

*/

class Solution {
public:
    
    bool helper(string& s, vector<string>& words, int i, int dp[]){
        
        if( i >= s.size()){
            return true;
        }
        
        if(dp[i]!=-1){
            return dp[i];
        }
        
        int ans = false;
        
        for(string word : words){
         
            if(s.substr(i, word.size()) == word){
                ans = ans || helper(s, words, i + word.size(), dp);
            }
        }
        
        return dp[i] = ans;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        int dp[n] ;
        memset(dp, -1, sizeof(dp));
        
        return helper(s, wordDict, 0, dp);
    }
};
