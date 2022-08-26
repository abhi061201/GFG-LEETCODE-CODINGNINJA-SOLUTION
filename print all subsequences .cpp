POWER SET
=========
TC-- O(n*(2^n));
sc= O(1)

#include<iostream>
#include<math.h>
using namespace std;
class print{
    public:
    int count=0;
    void printAllPossible_subsequences(string s){
    
    int n= s.length();
    for(int i=1; i<pow(2,n); i++){
        string temp;
        for(int j=0; j<n; j++){
            if(i&(1<<j))temp.push_back(s[j]);
        }
        count++;
        cout<<temp<<endl;
    }
}
};

int main(){
    string s;
    cin>>s;
    print p;
    p.  printAllPossible_subsequences(s);
  cout<<p.count;
    return 0;
}



==========================================================
    
    RECURSIVE APPROACH
    ======
    
 TC=O(2^n)
sc= O(1)

#include<iostream>
using namespace std;

class print{
    public:
    void printallsubseq(string s){
        go(0, s,"");
    }
    void go(int i, string s, string temp){
        if(i==s.length()){
            cout<<temp<<endl;
            return ;
        }
        temp.push_back(s[i]);
        go(i+1, s,temp);
        temp.pop_back();
        go(i+1, s, temp);
    }
    
    
};
int main(){
    
    string s;
    cin>>s;
    print p;
    p.printallsubseq(s);
    
    
    
    return 0;
}

    
