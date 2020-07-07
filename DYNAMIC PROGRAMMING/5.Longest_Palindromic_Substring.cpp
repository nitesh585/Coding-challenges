/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:

Input: "cbbd"
Output: "bb"

*/


class Solution {
public:
    int ExpandCenter(string s, int left, int right){
        int n = s.length();
        
        if(n==0 || left > right) return 0;
        
        while(left>=0 && right<n && s[left]==s[right]){
            left--;
            right++;
        }
        
        return right-left-1;
    }
    
    string longestPalindrome(string s) {
        if(s=="") return "";
        
        int n = s.length();
        int end = 0;
        int start=0;
        
        for(int i=0; i<n; i++){
            int len1 = ExpandCenter(s, i, i);
            int len2 = ExpandCenter(s, i, i+1);
            int  len = max(len1, len2);
            
            if(len > (end-start) ){
                start = i - ( (len-1)/ 2); 
                end = i + (len/2);
            }
        }
        
        return s.substr(start, end-start+1);
    }
};
