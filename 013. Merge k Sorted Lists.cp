public ListNode merge(ListNode l1, ListNode l2){
        ListNode mergedList = new ListNode(0);
        ListNode dummy = mergedList;

        while(l1 != null && l2 != null){
            if(l1.val <=l2.val){
                dummy.next = l1;
                l1 = l1.next;
            }
            else{
                dummy.next = l2;
                l2 = l2.next;
            }

            dummy = dummy.next;
        }

        while(l1 != null){
            dummy.next = l1;
            l1 = l1.next;
            dummy = dummy.next;
        }

        while(l2 != null){
            dummy.next = l2;
            l2 = l2.next;
            dummy = dummy.next;
        }

        // dummy = mergedList.next;
        // while(dummy !=null){
        //     Console.Write(dummy.val);
        //     dummy = dummy.next;
        // }
        // Console.WriteLine(" ");

        return mergedList.next;
    }

    public ListNode MergeKLists(ListNode[] lists) {
        ListNode ans = new ListNode(0);
        ListNode dummy = ans;

        for(int i=0;i<lists.Length;i++){          
            dummy.next = merge(dummy.next,lists[i]);
        }

        return ans.next;
    }
