/*
 Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

*/

class Solution {
public:
    
    void generateAll(string str, int open,int close, vector<string>& ans){
        if(open==0 && close==0){
            cout<<str<<endl;
            ans.emplace_back(str);
            return;
        }
        
        if(open>0){
            generateAll(str+'(', open-1, close, ans);    
        }
        
        if(close>open){
            generateAll(str+')', open, close-1, ans);    
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        
        generateAll("", n, n, ans);
        
        return ans;
    }
};
