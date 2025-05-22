public ListNode DeleteDuplicates(ListNode head) {
        ListNode start = head;
        while(head != null){
            while(head.next !=null && head.val == head.next.val){
                head.next = head.next.next;
            }

            head = head.next;
        }

        return start;
    }
