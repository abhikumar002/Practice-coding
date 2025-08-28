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
        ListNode p1 = head;
        ListNode start = null;

        while(head !=null){
            ListNode temp = head; 
            head = head.next;
            temp.next = start;
            start = temp;
        }

        return start;
    }
}




// ListNode temp = head.next;
//             head.next = start;
//             start = temp;
//             temp = temp.next;
//             temp.next = head;
//             head = temp;