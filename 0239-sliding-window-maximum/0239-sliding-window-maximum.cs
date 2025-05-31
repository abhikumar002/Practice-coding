public class Solution {
    public int[] MaxSlidingWindow(int[] nums, int k) {
        int maxi = int.MinValue;
        PriorityQueue<int,int> pq = new PriorityQueue<int,int>();
        List<int> ans = new List<int>();

        for(int i = 0; i < k; i++){
            pq.Enqueue(i, -nums[i]);
        }
        ans.Add(nums[pq.Peek()]);     
        
        for(int i=k;i<nums.Length;i++){
            pq.Enqueue(i,-nums[i]);
            while(pq.Count > 0 && pq.Peek() <= i - k){
                pq.Dequeue();
            }
            ans.Add(nums[pq.Peek()]);      
        }
        return ans.ToArray();
    }
}