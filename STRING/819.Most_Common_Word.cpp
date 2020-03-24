/*
Given a paragraph and a list of banned words, return the most frequent word that is not in the list of banned words.  It is guaranteed there is at least one word that isn't banned, and that the answer is unique.

Words in the list of banned words are given in lowercase, and free of punctuation.  Words in the paragraph are not case sensitive.  The answer is in lowercase.

 

Example:

Input: 
paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
banned = ["hit"]
Output: "ball"
Explanation: 
"hit" occurs 3 times, but it is a banned word.
"ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph. 
Note that words in the paragraph are not case sensitive,
that punctuation is ignored (even if adjacent to words, such as "ball,"), 
and that "hit" isn't the answer even though it occurs more because it is banned.



NOTE:
    1 <= paragraph.length <= 1000.
    0 <= banned.length <= 100.
    1 <= banned[i].length <= 10.
    The answer is unique, and written in lowercase (even if its occurrences in paragraph may have uppercase symbols, and even if it is a proper noun.)
    paragraph only consists of letters, spaces, or the punctuation symbols !?',;.
    There are no hyphens or hyphenated words.
    Words only consist of letters, never apostrophes or other punctuation symbols.

*/

class Solution {
public:
  
    string mostCommonWord(string paragraph, vector<string>& banned) {
        vector<string> arr;
        unordered_map<string,int> hmap;
        unordered_set<string> set;
        string temp="";
        string s;
        if(paragraph.size()==0)
            return s;
        for(int i=0;i<paragraph.size();i++){
            if(paragraph[i]=='.' || paragraph[i]=='"' || paragraph[i]==',' || paragraph[i]=='!' || paragraph[i]=='?' || paragraph[i]==';' || paragraph[i]=='\''){
                paragraph[i]=' ';
            }
        }
        
        transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower); 
        for(int i=0;i<paragraph.size();i++){
            if(paragraph[i]!=' '){
                temp+=paragraph[i];
            }else{
                arr.push_back(temp);
                temp="";
            }
        }
        
        arr.push_back(temp);
        for(int i=0;i<arr.size();i++){ 
            if(arr[i]!=""){
                hmap[arr[i]]++;
            }
        }
        int max=INT_MIN;
        int j=0;
        for(int i=0;i<banned.size();i++){
            if(hmap.find(banned[i])!=hmap.end()){
                hmap[banned[i]]=-1;
            }
        }
        
        for(auto x:hmap){
            if(x.second>max){
                max=x.second;
                s=x.first;
            }   
        }
        return s;
    }
};
