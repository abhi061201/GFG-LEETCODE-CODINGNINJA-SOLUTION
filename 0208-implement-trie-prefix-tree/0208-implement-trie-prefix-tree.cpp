class TrieNode{
    public:
    TrieNode* links[26];
    int end;
    
    TrieNode(){
        for(int i=0; i<26; i++)links[i]=NULL;
        end=0;
    }
    
};
class Trie {
public:
    TrieNode *root;
    Trie() {
        root= new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *temp= root;
        for(auto it: word){
            if(!temp->links[it-'a']){
                temp->links[it-'a']= new TrieNode();
            }
            temp = temp->links[it-'a'];
        }
        temp->end=1;
    }
    
    bool search(string word) {
        TrieNode *temp= root;
        for(auto it: word){
            if(!temp->links[it-'a'])return false;
            temp= temp->links[it-'a'];
        }
        return temp->end;
        
    }
    
    bool startsWith(string prefix) {
        TrieNode *temp= root;
        for(auto it: prefix){
            if(!temp->links[it-'a'])return false;
            temp= temp->links[it-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */