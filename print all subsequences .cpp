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



    
