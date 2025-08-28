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
    //Reverse LinkedList
    public ListNode ReverseList(ListNode head) {
        ListNode start = null;

        while(head != null){
            ListNode temp = head;
            head = head.next;
            temp.next = start;
            start = temp;
        }

        return start;
    }

    public void ReorderList(ListNode head) {
        ListNode head1 = head;
        ListNode slow = head;
        ListNode fast = head;

        while(fast.next != null && fast.next.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }
        
        ListNode second = slow.next;
        slow.next = null;

        ListNode secondreverse = ReverseList(second);
        ListNode ans = new ListNode(0);
        ListNode start = ans;

        // ListNode dummy = secondreverse;
        // while(dummy != null){
        //     Console.WriteLine(dummy.val);
        //     dummy = dummy.next;
        // }
        while(head1 != null && secondreverse != null){
            ans.next = head1;
            ans = ans.next;
            head1 = head1.next;
            ans.next = secondreverse;
            ans = ans.next;
            secondreverse = secondreverse.next;
        }

        if(head1 != null) { ans.next = head1; ans = ans.next;}
        if(secondreverse != null) { ans.next = secondreverse; ans = ans.next;}

        head = start.next;
    }
}