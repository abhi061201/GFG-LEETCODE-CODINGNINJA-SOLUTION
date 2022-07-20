

struct Trienode{
 Trienode * links[26];
 bool isEOW; 

 Trienode(){
    for(int i=0 ; i<26 ; i++){
        links[i]=NULL;
    }
    isEOW= false; 
 }

};
class Trie{
 
 Trienode *root ; 
 int no_of_words;
public:
 Trie(){
    root= new Trienode();
    no_of_words=0 ; 
 }
 
 void insert(string s){
    Trienode* temp= root; 
    for(auto it: s){
        if(temp->links[it-'a']==NULL){
            temp->links[it-'a']= new Trienode();
        }
        temp=temp->links[it-'a'];
    }
    temp->isEOW= true;
 }

 bool search(string s){
    Trienode * temp= root ; 
    for(auto it : s){
        if(temp->links[it-'a']==NULL){
            return false;
        }
        temp=temp->links[it-'a'];
    }
    return temp->isEOW;
 }
 bool startsWith(string s){
     Trienode * temp= root ; 
     for(auto it : s){
         if(temp->links[it-'a']==NULL){
             return false;
         }
         temp= temp->links[it-'a'];
     }
     return true ;
 }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
