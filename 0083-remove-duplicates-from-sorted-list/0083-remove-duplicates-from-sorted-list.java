/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if(head ==null || head.next==null )return head;
        ListNode tail= head.next, temp = head;
        while(temp!=null && tail!=null)
        {
            if(temp.val == tail.val)
            {
                tail= tail.next;
                temp.next = tail;
            }
            else
            {
                temp= temp.next;
                tail= tail.next;
            }
            
        }
        return head;
    }
}