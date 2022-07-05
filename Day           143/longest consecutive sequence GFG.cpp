// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
      int a[100002];
      memset(a, 0,sizeof(a));
      for(int i=0 ; i<n ; i++){
          a[arr[i]]++;
      }
      int ans=0;
      int count=0;
      for(int i=0 ; i<=100001; i++){
          ans= max(ans,count);
          if(a[i]>0)count++;
          
          else count=0;
      }
      return ans;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends
