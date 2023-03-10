/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* temp;
    int i=0;
    vector<int>v;
    set<int>se;
    Solution(ListNode* head) {
        temp= head;
        while(temp)
        {
            v.push_back(temp->val);
            temp= temp->next;
        }
        // vector<int>x(se.begin(), se.end());
        // v=x;
    }
    
    int getRandom() {
        int x= rand()%v.size();
        return v[x];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */