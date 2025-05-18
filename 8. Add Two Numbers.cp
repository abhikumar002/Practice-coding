public ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
        int carry = 0;
        ListNode start = new ListNode(0);
        ListNode head = start;

        while(l1 != null || l2 != null){
            int val1 = l1 != null ? l1.val : 0;
            int val2 = l2 != null ? l2.val : 0;

            int sum = val1 + val2  + carry;
            carry = sum / 10;

            head.next = new ListNode(sum % 10);
            head = head.next;

            if(l1 !=null) l1 = l1.next;
            if(l2 !=null) l2 = l2.next;
        }

        if (carry > 0) {
            head.next = new ListNode(carry);
        }

        return start.next;
    }
