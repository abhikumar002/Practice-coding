public class Solution {
    public Node CopyRandomList(Node head) {
        
        Node head1 = head;

        //1 step 
        while(head !=null){
            Node dummy = new Node(head.val);
            Node temp = head.next;
            head.next = dummy;
            dummy.next = temp;
            head = head.next.next;
        }

        head = head1;

        //2 Step
        while(head !=null){
            if(head.random !=null){
                Node dummy = head.random;
                // Console.WriteLine(dummy.val);
                head.next.random = dummy.next;
            }
            head = head.next.next;
        }

        head = head1;
        Node ans = new Node(0);
        Node start = ans;
        while(head !=null){
            ans.next = head.next;
            ans = ans.next;
            head.next = head.next.next;
            head = head.next;
        }

        return start.next;

    }
}
