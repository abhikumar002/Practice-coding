public class Solution {
    public bool ContainsDuplicate(int[] nums) {
        HashSet<int> hs = new HashSet<int>();
        
        foreach(var x in nums)  hs.Add(x);
        
        return hs.Count != nums.Length;
    }
}