class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq(piles.begin(), piles.end());
        while(k--)
        {
            int max_ele= pq.top();
            pq.pop();
            max_ele -= max_ele/2;
            pq.push(max_ele);
            
        }
        int sum=0;
        while(!pq.empty())
        {
            sum+= pq.top();
            pq.pop();
        }
        return sum;
            
    }
};