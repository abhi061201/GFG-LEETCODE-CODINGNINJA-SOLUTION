//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	vector<string>ans;
	vector<string> AllPossibleStrings(string s){
	    go(0, s, "");
	    
	    sort(ans.begin(), ans.end());
	    return ans;
	}
	void go(int i, string &s , string temp)
	{
	    if(i>= s.length())
	    {
	        if(temp.size()>0)ans.push_back(temp);
	        return ;
	    }
	    
	    // take
	    temp.push_back(s[i]);
	    go(i+1, s, temp);
	    temp.pop_back();
	    go(i+1 , s, temp);
	}
	
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends