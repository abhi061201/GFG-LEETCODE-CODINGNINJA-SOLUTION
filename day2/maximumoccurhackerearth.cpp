#include <bits/stdc++.h>
using namespace std;

int main(){
     
	 string s;
	getline(cin, s); // getline function is used to take input whole line 

	 map <char ,int> mp;
	 for(int i=0 ;i<s.length() ;i++){
		 mp[s[i]]++;

	 }
// cout<<mp.begin()->first<<" " <<mp.begin()->second;
    int a=0;
	char c;
  for(auto x: mp){
	  if(a<x.second){
		a= x.second;
		c= x.first;
	  }

  }

cout<<c<<" " <<a<<"\n";
return 0;
}
























