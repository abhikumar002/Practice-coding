public void ReorderList(ListNode head) {
        if (head ==null || head.next ==null) return;

        ListNode slow = head, fast = head;
        while (fast != null && fast.next !=null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        ListNode second = slow.next;
        slow.next = null;
        ListNode node = null;

        while (second !=null) {
            ListNode temp = second.next;
            second.next = node;
            node = second;
            second = temp;
        }

        second = node;
        ListNode head2 = second;
        ListNode head1 = head;

        while (head1 != null && head2 != null)
        {
            Console.WriteLine(head1.next.val);
            ListNode temp = head1.next;
            head1.next = head2;
            head1 = temp;

            temp = head2.next;
            head2.next = head1;
            head2 = temp;
        }

    }
