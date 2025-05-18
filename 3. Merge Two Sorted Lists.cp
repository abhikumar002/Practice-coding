public ListNode MergeTwoLists(ListNode list1, ListNode list2) {
        
        ListNode temp = new ListNode();
        ListNode start = new ListNode(0);
        ListNode dummy = start;

        while(list1 !=null && list2 !=null){
            if(list1.val > list2.val){
                dummy.next = list2;
                dummy = dummy.next;
                list2 = list2.next;
            }
            else{
                dummy.next = list1;
                dummy = dummy.next;
                list1 = list1.next;
            }
            
        }

        if(list1 !=null){
            dummy.next = list1;
        }

        if(list2 !=null){
            dummy.next = list2;
        }

        return start.next;
    }
