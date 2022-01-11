#include <iostream>
using namespace std;

int main() {
	
	int n;
	cin>>n;
	
	for(int i=1; i<=n ;i++){
	    int k=i;
	    while(k++<n) cout<<" ";
	  for(int j=n-i; j<n ;j++){
	      cout<<"*";
	  }
	  cout<<"\n";
	    
	    
	}
	return 0;
}
