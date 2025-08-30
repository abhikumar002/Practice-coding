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

    public ListNode Mergelist(ListNode l1,ListNode l2) {
        
        ListNode list = new ListNode(0);
        ListNode start = list;

        while(l1 != null && l2 != null){
            if(l1.val <= l2.val){
                list.next = l1;
                l1 = l1.next;
            }
            else{
                list.next = l2;
                l2 = l2.next;
            }        
            list = list.next;
        }

        if(l1 != null) list.next = l1;
        if(l2 != null) list.next = l2;

        return start.next;
    }

    public ListNode MergeKLists(ListNode[] lists) {
        
        int n = lists.Length;
        if(n < 1) return null;

        ListNode ans = new ListNode(0);
        ListNode dummy = ans;

        for(int i=0;i<n;i++){
            if (lists[i] == null) continue;
            dummy.next = Mergelist(dummy.next,lists[i]);
        }

        return ans.next;     
    }
}