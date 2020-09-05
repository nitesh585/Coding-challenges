/*
Given a sentence text (A sentence is a string of space-separated words) in the following format:

First letter is in upper case.
Each word in text are separated by a single space.

Your task is to rearrange the words in text such that all words are rearranged in an increasing order of their lengths. If two words have the same length, arrange them in their original order.

Return the new text following the format shown above.


Example 1:

Input: text = "Leetcode is cool"
Output: "Is cool leetcode"
Explanation: There are 3 words, "Leetcode" of length 8, "is" of length 2 and "cool" of length 4.
Output is ordered by length and the new first word starts with capital letter.

Example 2:

Input: text = "Keep calm and code on"
Output: "On and keep cx	alm code"
Explanation: Output is ordered as follows:
"On" 2 letters.
"and" 3 letters.
"keep" 4 letters in case of tie order by position in original text.
"calm" 4 letters.
"code" 4 letters.

Example 3:

Input: text = "To be or not to be"
Output: "To be or to be not"

Constraints:

    text begins with a capital letter and then contains lowercase letters and single space between words.
    1 <= text.length <= 10^5

*/

class Solution {
public:
    string arrangeWords(string text) {
        string tmp="";
        
        vector<pair<int,int>> vec;
        vector<string> str;
        int n;
        
        for(int i=0; i<text.length() ; i++){   
            if(text[i]==' '){
                tmp[0] = tolower(tmp[0]);
                str.emplace_back(tmp);
                n = str.size();
                
                vec.push_back({tmp.length() , n-1});
                
                tmp = "";
                
            }else{
                 tmp+=text[i];
            }
        }
        
        if(tmp.length()){
            str.emplace_back(tmp);
            n = str.size();
            vec.push_back({tmp.length() , n-1});
        }
        
        sort(vec.begin() , vec.end());
        string ans="";
        int i;
        
        for(i=0; i<vec.size()-1; i++){
            ans += str[vec[i].second] ;
            ans+=' ';
        }
        
        //  to not append extra space in the end of the string
        ans += str[vec[i].second] ;        
        ans[0] = toupper(ans[0]);

        return ans;
    }
};
