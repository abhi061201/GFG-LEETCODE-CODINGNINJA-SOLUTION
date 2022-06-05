string s;

void go(int i, string temp,int n,vector<string>&ans){
    if(i==n){
        if(temp.size()>0)ans.push_back(temp);
    }
    else {
        go(i+1,temp,n,ans);
        temp=temp+s[i];
        go(i+1,temp,n,ans);
    }
}

vector<string> subsequences(string str){
	s=str;
    int n= s.length();
	vector<string>ans;
	go(0,"",n,ans);
    return ans;
}
