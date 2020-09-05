/*
Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:

Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

 

Example 2:

Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

 

Note:

    The input string length won't exceed 1000.

*/

class Solution {
public:
    /* 
    First Approach :
    bool isPalindrome(string s){
        int n = s.size();
        
        for(int i=0, j=n-1; i<n/2; i++,j--){
            if(s[i]!=s[j]) return false;
        }
        
        return true;
    }
    
    int countSubstrings(string s) {
        int cnt=0;
        
        for(int i=0; i<s.size() ; i++){
            for(int j=1; j<=s.size()-i ; j++){
                if(isPalindrome(s.substr(i,j))){
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
    */
    
    int countSubstrings(string s) {
        int n = s.size();
        int ans=0, left, right;
        
        for(int center=0; center <= 2*n-1; ++center){
            left = center/2;
            right = left+center%2;
            
            while(left>=0 && right<n && s[left]==s[right]){
                ++ans;
                --left;
                ++right;
            }
            
        }
        
        return ans;
        
    }
    
};
