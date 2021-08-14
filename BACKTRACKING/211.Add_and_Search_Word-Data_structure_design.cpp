/*
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)

search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

Example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true

Note:
You may assume that all words are consist of lowercase letters a-z.

*/

class WordDictionary {
public:
    
    struct TrieNode{
      TrieNode* children[26];
      bool endword;
    };
    
    TrieNode* getNode(){
        TrieNode* node = new TrieNode;
        for(int i=0; i<26; i++){
            node->children[i] = NULL;
        }

        node->endword = false;
        return node;
    }
    
    TrieNode* root;
    /** Initialize your data structure here. */
    WordDictionary() {
        root = getNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* node = root;
        int idx;
        for(int i=0; i<word.size() ; i++){
            if(word[i]>='a' && word[i]<='z'){
                idx = word[i]-'a';
                if(!node->children[idx]){
                    node->children[idx] = getNode();
                }
                node = node->children[idx];
            }
        }
        node->endword =  true;
    }
    
    
    bool searchBactrack(string word, TrieNode* root){
        for(int i=0; i<word.size(); i++){
            if(word[i]!='.'){
                int idx = word[i]-'a';
                if(!root->children[idx]){
                    return false;
                }
                root = root->children[idx];
            }else{
                int j=0;
                bool found = false;
                for(; j<26; j++){
                    if(root->children[j]){
                        found|= searchBactrack(word.substr(i+1), root->children[j]);
                    }
                    if(found){
                        return true;
                    }
                }
                if(j==26){
                    return false;
                }
            }
        }   
        return root->endword;
    }
    
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
       return searchBactrack(word,root);
    }
    
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
