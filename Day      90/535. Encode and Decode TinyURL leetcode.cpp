class Solution {
public:

    // Encodes a URL to a shortened URL.
    string s1;
    string encode(string lu) {
        
        string s= lu.substr(1,lu.length());
         s1=lu[0];
        return  s;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string sl) {
        string s=s1;
        s+=sl;
        return s;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
