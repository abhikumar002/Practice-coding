public ListNode reverse(ListNode head){

        ListNode prev = null;
        ListNode current = head;
    
        while(current != null){
            ListNode next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }

    public ListNode ReverseKGroup(ListNode head, int k) {

        if (head == null || k == 1) {
            return head;
        }

        ListNode temp = head;
        for (int i = 0; i < k; i++) {
            if (temp == null) {
                return head;
            }
            temp = temp.next;
        }

        ListNode dummy = new ListNode(0);
        ListNode prevGroupEnd = dummy;
        ListNode current = head;

        while(current != null){

            ListNode groupStart = current;
            ListNode groupEnd = current;

            for (int i = 1; i < k && groupEnd != null; i++) {
                groupEnd = groupEnd.next;
            }

            if (groupEnd == null) {
                prevGroupEnd.next = groupStart;
                break;
            }

            ListNode nextGroupStart = groupEnd.next;
            groupEnd.next = null;

            ListNode reversedGroupHead = reverse(groupStart);
            prevGroupEnd.next = reversedGroupHead;

            prevGroupEnd = groupStart;
            current = nextGroupStart;
              
        }

        return dummy.next;
