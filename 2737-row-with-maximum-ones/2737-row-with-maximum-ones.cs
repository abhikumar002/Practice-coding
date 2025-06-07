public class Solution {
    public int[] RowAndMaximumOnes(int[][] mat) {
       int ans = int.MinValue;
       int index = 0;
       
       for(int i=0;i<mat.Length;i++){
            int prefsum = 0;
            for(int j=0;j<mat[0].Length;j++){
                prefsum+=mat[i][j]; 
                                        
            }
            
        if(ans < prefsum){
            ans = prefsum;
            index = i;
        } 

       }
       
       
       return [index,ans];
    }
}