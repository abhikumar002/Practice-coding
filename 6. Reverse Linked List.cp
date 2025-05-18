public ListNode ReverseList(ListNode head) { 

        ListNode Newhead =null;

        while(head != null){
            ListNode temp=head;
            head=head.next;
            temp.next=Newhead;
            Newhead=temp;
        }

        return Newhead;
    }
