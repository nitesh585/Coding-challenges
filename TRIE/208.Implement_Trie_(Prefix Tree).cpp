/*
Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true

Note:

    You may assume that all inputs are consist of lowercase letters a-z.
    All inputs are guaranteed to be non-empty strings.


*/

class Trie {
public:
    /** Initialize your data structure here. */
    struct TrieNode{
      TrieNode* children[26];
      bool endword;
    };
    
    TrieNode* getNode(){
        TrieNode* node = new TrieNode;
        
        node->endword = false;
        for(int i=0; i<26;i++){
            node->children[i] = NULL;
        }
        return node;
    }
    
    TrieNode* root;
    
    Trie() {
        root = getNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* tmp = root;
        for(int i=0; i<word.size() ; i++){
            int index = word[i]-'a';
            
            if(!tmp->children[index]){
                tmp->children[index] = getNode();
            }
            tmp = tmp->children[index];
        }
        
        tmp->endword = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* tmp = root;
        for(int i=0; i<word.size() ; i++){

            int index = word[i]-'a';
            
            if(!tmp->children[index]){
                return false;
            }
            tmp = tmp->children[index];
        }
        
        return tmp && tmp->endword;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        
        TrieNode* tmp = root;
        for(int i=0; i<prefix.size() ; i++){
            int index = prefix[i]-'a';
            
            if(!tmp->children[index]){
                return false;
            }
            tmp = tmp->children[index];
        }
        
        return tmp;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
