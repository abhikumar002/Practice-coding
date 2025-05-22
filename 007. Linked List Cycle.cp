public bool HasCycle(ListNode head) {

        ListNode first = head;
        ListNode second = head;

        while(second !=null && second.next !=null){
            
            first = first.next;
            second = second.next.next;
            if(first == second){
                return true;
            }
        }

        return false;
        
    }
