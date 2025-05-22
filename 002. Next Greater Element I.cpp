public int[] NextGreaterElement(int[] nums1, int[] nums2) {
        Dictionary<int,int> dic = new  Dictionary<int,int>();
        int n = nums2.Length;
        int m = nums1.Length;
        int[] ans = new int[m];

        Array.Fill(ans,-1);
        Stack<int> s = new Stack<int>();

        for(int i=n-1;i >=0;i--){
            while(s.Count > 0 && s.Peek() < nums2[i]){
                s.Pop();
            }
            if(s.Count == 0 || s.Peek() < nums2[i]) dic[nums2[i]] = -1;
            else{
                dic[nums2[i]] = s.Peek();
            }
            s.Push(nums2[i]);
        }
        
        int q =0;
        for(int i=0;i<m;i++){
            ans[q++] = dic[nums1[i]];
        }

        return ans;
    }
