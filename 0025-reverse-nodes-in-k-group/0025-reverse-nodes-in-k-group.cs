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
    public ListNode reverselist(ListNode head){
        ListNode start = null;
        while(head != null){
            ListNode temp = head;
            head = head.next;
            temp.next = start;
            start = temp;
        }

        return start;

    }
    public ListNode ReverseKGroup(ListNode head, int k) {

        if (head == null || k == 1) return head;

        ListNode temp = head;
        for (int i = 0; i < k; i++) {
            if (temp == null) {
                return head;
            }
            temp = temp.next;
        }

        ListNode start = new ListNode(0);
        ListNode prevnode = start;
        ListNode current = head;

        while(current != null){

            ListNode groupStart = current;
            ListNode groupEnd = current;

            for (int i = 1; i < k && groupEnd != null; i++) groupEnd = groupEnd.next;

            if(groupEnd == null){ prevnode.next = groupStart; break; }

            ListNode nextGroupStart = groupEnd.next;
            groupEnd.next = null;

            ListNode reverseGroupHead = reverselist(groupStart);
            prevnode.next = reverseGroupHead;

            prevnode = groupStart;
            current = nextGroupStart;

        }

        return start.next;
    }
}