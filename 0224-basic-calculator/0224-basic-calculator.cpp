class Solution {
public:
    int calculate(string& s, int si, int ei, unordered_map<int, int>& umap) {
        int curNum = 0, lastNum = 0, ans = 0;
        char operation = '+';
        for(int i=si; i<=ei; i++){
            if (isdigit(s[i])){
                curNum = curNum*10 + (s[i] - '0');
            }
            if (!isdigit(s[i]) && !iswspace(s[i]) || i == ei){
                if (s[i] == '('){
                    curNum = calculate(s, i+1, umap[i]-1, umap);
                    i = umap[i]+1;
                }
                if (operation == '+' || operation == '-'){
                    ans += lastNum;
                    lastNum = operation == '+' ? curNum: -curNum;
                }else if (operation == '*'){
                    lastNum = lastNum*curNum;
                }else if (operation == '/'){
                    lastNum = lastNum/curNum;
                }
                if (i <= ei){
                    operation = s[i];
                }
                curNum = 0;
            }
        }
        ans += lastNum;
        return ans;
    }
    int calculate(string& s) {
        stack<int> stk;
        int n = s.size();
        unordered_map<int, int> umap;
        for(int i=0; i<n; i++){
            if (s[i] == '('){
                stk.push(i);
            }else if (s[i] == ')'){
                umap[stk.top()] = i;
                stk.pop();
            }
        }
        return calculate(s, 0, n-1, umap);
    }
};