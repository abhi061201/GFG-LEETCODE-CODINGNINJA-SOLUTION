

 class WordDictionary {
    WordDictionary * links[26];
     bool isEOW;
    
     bool searchhelper(int i, string word , WordDictionary *temp){
         if(i==word.length()){
             return temp->isEOW;
         }
         WordDictionary* root = temp; 
         if(word[i]=='.'){
             bool ans=false;
            for(auto it: root->links){
               if(it)ans= ans|| searchhelper(i+1, word, it);
            }
             return ans;
             
         }
         else if(temp->links[word[i]-'a']){
             return searchhelper(i+1 , word , temp->links[word[i]-'a']);
         }
         else return false;
         
         
         
     }
    
public:
    WordDictionary() {
        for(int i=0 ; i<26; i++){
            links[i]= NULL; 
            
        }
        isEOW= false; 
    }
    
    void addWord(string word) {
        WordDictionary* temp= this;
        for(auto it: word){
            if(temp->links[it-'a']==NULL){
                temp->links[it-'a']=new WordDictionary();
            }
            temp= temp->links[it-'a'];
        }
        temp->isEOW= true;
    }
    
    bool search(string word) {
       WordDictionary* temp = this; 
        return searchhelper(0, word , temp);
    }
    
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */