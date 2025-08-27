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
    public ListNode MergeTwoLists(ListNode l1, ListNode l2) {
        
        ListNode dummy = new ListNode(0);
        ListNode start = dummy;

        while(l1 !=null && l2 != null){
            Console.WriteLine(l1.val+" "+l2.val);
            if(l1.val <= l2.val){
                dummy.next= l1;
                l1 = l1.next;
            }
            else{
                dummy.next= l2;
                l2 = l2.next;
            }
            dummy = dummy.next;
        }

        if(l1 != null) dummy.next = l1;
        if(l2 != null) dummy.next = l2;

        return start.next;
    }
}