//{ Driver Code Starts
// Driver code

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
  public:
    int findOnce(int arr[], int n)
    {
        int mid,  l=0, h= n-1;
        while(h-l>1)
        {
            mid= (l+h)/2;
            int x= get(mid, n, arr);
            if(x==-1)return arr[mid];
            if(x%2==0)
            {
                l= mid;
                
            }
            else h= mid;
        }
        if(h%2==0)return arr[h];
        return arr[l];
    }
    int get(int x, int n, int arr[])
    {
        if(x-1 >=0 && arr[x]== arr[x-1])return x-1;
        if(x+1 < n && arr[x] ==arr[x+1])return x;
        return -1;
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
        int A[n];
        for(int i = 0;i < n;i++)
        {
            cin>>A[i];
        }
        
        Solution ob;
        
        int res = ob.findOnce(A,n);
        cout << res << endl;
    }
    
    return 0;
}
// } Driver Code Ends