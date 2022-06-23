class Solution {
public:
    static bool com(vector<int> a, vector<int>b){
        return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(),com);
        int n= courses.size();
        priority_queue<int>pq;
        int start=0;
        for(int i=0 ; i<n ; i++){
            int x= courses[i][0];
            int y = courses[i][1];
            if(start+x <=y){
                start+=x;
                pq.push(x);
            }
            else {
                if(pq.size() && pq.top() > x) {
                start-= pq.top();
                
                pq.pop();
                start+=x;
                pq.push(x);
            }
            }
            
        }
        return pq.size();
        
    }
};
