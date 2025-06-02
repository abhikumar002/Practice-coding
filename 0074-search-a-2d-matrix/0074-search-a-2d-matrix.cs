public class Solution {
    public bool SearchMatrix(int[][] matrix, int target) {
        int n = matrix.Length;
        int m = matrix[0].Length;

        if(matrix[0][0] == target) return true;

        int up = 0, down = n-1;
        while(up < down){
            int mid = (up + down) / 2;
            // Console.WriteLine(up + " "+down+" -> " + mid);
            if(matrix[mid][0] ==target) return true;
            else if(matrix[mid][0] < target) up = mid+1;
            else down = mid-1;
        }

        int targetrow = up;
        if (targetrow >= n || matrix[targetrow][0] > target) 
        {
            targetrow = targetrow - 1;
        }
        if(targetrow < 0) return false;

        int left = 0, right = m-1;
        while(left <= right){
            int mid = (left + right) / 2;
            //Console.WriteLine(left + " "+right+" -> " + mid);
            if(matrix[targetrow][mid] == target) return true;
            else if(matrix[targetrow][mid] < target) left = mid+1;
            else right = mid-1;
        }
        return false;

    } 
}