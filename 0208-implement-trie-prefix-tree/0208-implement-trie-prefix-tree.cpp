class TrieNode{
    public:
    TrieNode* links[26];
    int eow;
    TrieNode()
    {
        for(int i=0;i<26;i++)
            links[i]=NULL;
        eow=0;
    }
};
class Trie {
    TrieNode* root;
public:
    Trie() {
        root= new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* temp= root;
        for(auto it: word)
        {
            if(!temp->links[it-'a'])
            {
                temp->links[it-'a']= new TrieNode();
            }
            temp= temp->links[it-'a'];
        }
        temp->eow++;
    }
    
    bool search(string word) {
        TrieNode* temp= root;
        for(auto it: word)
        {
            if(!temp->links[it-'a'])return false;
            temp= temp->links[it-'a'];
        }
        return temp->eow;
    }
    
    bool startsWith(string word) {
        TrieNode* temp= root;
        for(auto it: word)
        {
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