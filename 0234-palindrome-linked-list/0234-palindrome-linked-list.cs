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

    public bool IsPalindrome(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;

        while(fast.next !=null && fast.next.next != null){
            fast = fast.next.next;
            slow = slow.next;
        }

        ListNode second = slow.next;
        slow.next = null;

        //Reverse
        ListNode third = ReverseList(second);
        ListNode dummy = third;

        while(dummy != null){
            Console.WriteLine(dummy.val);
            dummy = dummy.next;
        }
        
        while(head != null && third != null){
            if(head.val != third.val) return false;
            head = head.next;
            third = third.next;
        }

        return true;
    }
}