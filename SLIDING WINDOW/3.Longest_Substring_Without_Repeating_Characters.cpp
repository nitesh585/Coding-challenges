/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 

Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.


*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s ==""){
            return 0;
        }
        int count=0;
        set<char> myset;
        
        for(int i=0,j=0; i<s.length() && j<s.length() ;){
            if(myset.find(s[i]) == myset.end()){
                myset.insert(s[i++]);
                count = max(count , i-j);
            }else{
                myset.erase(myset.find(s[j++]));   
            }
        }
        
        return count;
    }
};
