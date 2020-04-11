/*
Given a string S, return the "reversed" string where all characters that are not a letter stay in the same place, and all letters reverse their positions.

 

Example 1:

Input: "ab-cd"
Output: "dc-ba"

Example 2:

Input: "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"

Example 3:

Input: "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"


*/

class Solution {
public:
    string reverseOnlyLetters(string S) {
        string res="";
        for(char c:S){
            if((c>='a' && c<='z') || (c>='A' && c<='Z') ) res = c+res;
        }
        
        int n  = res.length();
        
        for(int i=0; i<S.length() ; i++){
            if( !((S[i]>='a' && S[i]<='z') || (S[i]>='A' && S[i]<='Z')) ){
                res = res.substr(0,i)+S[i]+res.substr(i,n);
            }
        }
        
        return res;
    }
};
