class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq(stones.begin(), stones.end());
        int x, y;
        while(pq.size()>1)
        {
            x= pq.top(); pq.pop();
            y= pq.top();pq.pop();
            if(x==y)continue;
            else pq.push(x-y);
        }
        return pq.size()==0?0 :pq.top();
        
    }
};