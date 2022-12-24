//{ Driver Code Starts
//Initial Template for C


#include <stdio.h>

// } Driver Code Ends
//User function Template for C

void toBinary(int n)
{
    int binarynum[32];
    int i=0;
    while(n>0)
    {
        binarynum[i]= n%2;
        n=n/2;
        i++;
    }
    for(int j= i-1 ; j>=0 ; j--)
    {
        printf("%d",binarynum[j]);
    }
    
        
}

//{ Driver Code Starts.

int main() {
	//code
	
	int t;
	scanf("%d", &t);
	
	
	while(t--)
	{
	    int n;
	    scanf("%d", &n);
	    
	    toBinary(n);
	    printf("\n");
	}
	return 0;
}
// } Driver Code Ends