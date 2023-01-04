//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class TrieNode{
    public:
    int eow;
    TrieNode* links[26];
    TrieNode()
    {
        eow=0;
        for(int i=0; i<26 ; i++)
        {
            links[i]=NULL;
        }
    }
};

class Trie{
    TrieNode* root;
    public:
    Trie(){
        root= new TrieNode();
    }
    void insert(string &s)
    {
        TrieNode* temp= root;
        for(auto it: s)
        {
            if(!temp->links[it-'a'])temp->links[it-'a']= new TrieNode();
            temp= temp->links[it-'a'];
        }
        temp->eow=1;
        
    }
    bool checkPrefix(string &s)
    {
        TrieNode* temp= root;
        for(auto it:s )
        {
            temp= temp->links[it-'a'];
            if(temp->eow==0)return 0;
        }
        return temp->eow;
    }
};
class Solution
{
public:
    string longestString(vector<string> &words)
    {
        Trie t;
        for(auto it: words)
        {
            t.insert(it);
            
        }
        string ans;
        for(auto it: words)
        {
            if(t.checkPrefix(it) )
            {
                if(ans.length()==it.length())ans= min(ans, it);
                if(ans.length() < it.length())ans= it;
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends