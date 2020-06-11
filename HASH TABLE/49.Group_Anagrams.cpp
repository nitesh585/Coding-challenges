Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

Note:

    All inputs will be in lowercase.
    The order of your output does not matter.




class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> copy = strs;
        
        for(int i  = 0; i<copy.size() ; i++)
            sort(copy[i].begin(), copy[i].end());
        
        
        vector<vector<string>> ans;
        
        unordered_map<string,vector<string>> mymap;
        for(int i=0;i<copy.size(); i++)
            mymap[copy[i]].push_back(strs[i]);
        
        
        for(auto i = mymap.begin() ; i!=mymap.end() ; i++)
            ans.push_back(i->second);    
        
        
        return ans;
    }
};
