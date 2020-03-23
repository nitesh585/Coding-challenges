/*
Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

Example 1:

Input: ["abcw","baz","foo","bar","xtfn","abcdef"]
Output: 16 
Explanation: The two words can be "abcw", "xtfn".
*/

class Solution {
public:
   
    int maxProduct(vector<string>& words) {
        int maxlen=0;
        vector<int> ints(words.size());
        //setting the bit to track where particular character present
        for(int i=0;i<words.size();i++){
            string tmp = words[i];
            for(int j=0;j<tmp.size();j++){
                ints[i] |= (1<<(tmp[j]-'a'));
            }
        }
        
        for(int i=0;i<ints.size() ;i++ ){
            for(int j=i+1; j<ints.size() ; j++){
                int product_length = words[i].length()*words[j].length();
                if(product_length <= maxlen)continue;
                if(!(ints[i]&ints[j])){  // true if no two words share common letters
                    maxlen = max(maxlen,product_length);
                }
            }
        }
        return maxlen;
    }
};
