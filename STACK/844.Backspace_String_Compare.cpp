/*
Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".

Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".

Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".

Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".

Note:

    1 <= S.length <= 200
    1 <= T.length <= 200
    S and T only contain lowercase letters and '#' characters.


*/

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> stk1, stk2;
        for(char c: S){
            if(c=='#'){
                if(!stk1.empty()){
                    stk1.pop();
                }
            }else{
                stk1.push(c);
            }
        }
        
        
        for(char c: T){
            if(c=='#'){
                if(!stk2.empty()){
                    stk2.pop();
                }
            }else{
                stk2.push(c);
            }
        }
        
        S = ""; T = "";
        while(!stk1.empty()){
            S+=stk1.top();
            stk1.pop();
        }
        while(!stk2.empty()){
            T+=stk2.top();
            stk2.pop();
        }
        return S==T;
    }
};
