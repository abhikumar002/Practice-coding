public class Solution {
    public int FindLHS(int[] nums) {
        
        Dictionary<int,int> dic = new Dictionary<int,int>();       
        foreach(var x in nums){
            if(dic.ContainsKey(x)){
                dic[x]++;
            }
            else{
                dic[x] = 1;
            }
        }

        int count = 0;
        foreach (var x in dic){
            if(dic.ContainsKey(x.Key +1)){
                count = Math.Max(count, x.Value + dic[x.Key+1]);
            }
        }

       
        return count;
    }
}