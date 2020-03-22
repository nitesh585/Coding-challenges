/*
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

Example:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"

Output: ["AAAAACCCCC", "CCCCCAAAAA"]


*/
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int> m;
        vector<string> res;
        if(s.length()<10){
            return res;
        }
        
        for(int i=0;i<s.length()-9;i++){
            m[s.substr(i,10)]++;
        }
        
        for(auto i = m.begin() ; i!=m.end() ; i++){
            if(i->second>1){
                res.push_back(i->first);
            }
        }
        return res;
        
    }
};
