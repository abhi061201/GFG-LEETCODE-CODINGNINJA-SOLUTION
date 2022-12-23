class TrieNode{
    public:
    TrieNode* links[26];
    int end;
    TrieNode(){
        for(int i=0; i<26; i++)links[i]=NULL;
        end=0;
    }
};
class MagicDictionary {
    TrieNode* root;
public:
    
    MagicDictionary() {
        root= new TrieNode();
    }
    
    void insert(string &word){
        TrieNode* temp= root;
        for(auto it: word){
            if(!temp->links[it-'a'])temp->links[it-'a']= new TrieNode();
            temp= temp->links[it-'a'];
        }
        temp->end=1;
    }
    void buildDict(vector<string> dict) {
        for(auto it: dict){
            insert(it);
        }
    }
    
    bool search(string searchWord) {
        TrieNode* temp= root;
        return go(0,0,temp, searchWord);    
    }
    bool go(int index,int count,TrieNode* temp, string &s){
        if(index==s.length())
        {
            if(count==1 && temp->end==1)return 1;
            return 0;
        }
        if(count>1)return 0; 
           bool ans=0;
            for(int i=0; i<26; i++)
            {
                if(temp->links[i]!= NULL)
                {
                    if(i==s[index]-'a')ans= ans| go(index+1 , count, temp->links[i], s);
                    else ans= ans| go(index+1, count+1, temp->links[i], s);
                }
                if(ans==1)return ans;
            }
          return ans;
       }
    
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */