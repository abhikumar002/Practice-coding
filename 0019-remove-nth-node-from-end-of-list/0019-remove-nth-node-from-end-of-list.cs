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
    public ListNode RemoveNthFromEnd(ListNode head, int n) {
        if(head == null || head.next == null) return null;

        int count = 0;
        ListNode head1 = new ListNode(0);
        head1.next = head;

        ListNode itr = head;
        while(itr !=null){
            count++;
            itr = itr.next;
        }

        count -=n;
        ListNode head2 = head1;
        for(int i=0; i<count;i++){
            head2 = head2.next;
        }
        head2.next = head2.next.next;

        return head1.next;
    }
}