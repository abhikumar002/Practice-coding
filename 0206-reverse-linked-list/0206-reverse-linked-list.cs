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
    public ListNode ReverseList(ListNode head) { 
        if(head == null || head.next == null) return head;
        ListNode p1 = head;
        ListNode p2 = head.next;
        bool first = true;

        while(true){
            if(p2 == null) return p1;
            if(first) {
                p1.next = null;
                first = false;
            }
            ListNode temp = p2.next;
            p2.next = p1;
            p1 = p2;
            p2 = temp;
        }

        return p1;
    }
}




// ListNode temp = head.next;
//             head.next = start;
//             start = temp;
//             temp = temp.next;
//             temp.next = head;
//             head = temp;