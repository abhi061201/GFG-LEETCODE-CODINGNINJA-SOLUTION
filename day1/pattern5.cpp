#include <iostream>
using namespace std;

int main() {
	
	int n;
	cin>>n;
	
for(int i=1 ;i<=n/2 ;i++){
    for(int j=1 ;j<i ;j++ )cout<<" ";
    cout<<"*";
    for(int j=1 ;j<=n-2*i ;j++)cout<<" ";
    cout<<"*";
     cout<<"\n";
    
}
if((n&1)!=0){
 for(int j=1 ;j<=n/2 ;j++ )cout<<" ";
    cout<<"*";
    cout<<"\n";

}
 
n=n/2;
for(int i=1 ;i<=n ;i++ ){
    
    for(int j=1 ;j<=n-i ;j++)cout<<" ";
    cout<<"*";
    for(int j=1 ;j<2*i-1 ;j++)cout<<" ";
    cout<<"*";
    cout<<"\n";
}

	return 0;
}
