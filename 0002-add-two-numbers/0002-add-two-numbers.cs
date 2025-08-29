/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
        int carry = 0;
        ListNode ans = new ListNode(0);
        ListNode dummy = ans;

        while(l1 != null || l2 != null){
            
            int temp = ((l1 == null ? 0 : l1.val) + (l2 == null ? 0 : l2.val));
            if(carry > 0) { temp += carry; carry -= carry; }

            if(temp > 9){
                temp = temp%10;
                carry += 1;
            } 

            ListNode d = new ListNode(temp);
            dummy.next = d;
            dummy = dummy.next;

            if(l1 != null) l1 = l1.next;
            if(l2 != null) l2 = l2.next;
        }

        if(carry > 0){
            ListNode t = new ListNode(carry);
            dummy.next = t;
        } 

        return ans.next;
    }
}