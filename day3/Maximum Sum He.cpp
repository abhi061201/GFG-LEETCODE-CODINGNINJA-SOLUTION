#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){


ll n;
cin>>n;
ll arr[n];

for(int i=0 ;i<n ;i++)cin>>arr[i];
sort(arr, arr+n);

ll sum=arr[n-1];
ll count=1;
for(int i=n-2 ;i>=0 ;i--){
if(arr[i]<0)break;
else {
     count++;
    sum+=arr[i];
}
}
cout<<sum<<" "<<count;


    
    
    
    return 0;
    
}
