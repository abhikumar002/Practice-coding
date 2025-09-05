public class Solution {
    public double FindMedianSortedArrays(int[] nums1, int[] nums2) {
        if(nums2.Length < nums1.Length) return FindMedianSortedArrays(nums2,nums1);
         int n=nums1.Length; int m=nums2.Length;
        
         int low=0; int high=n;
         while(low<=high){
             int it1=(low+high)/2;
             int it2=(m+n+1)/2-it1;
             
             int l1= it1==0 ? int.MinValue : nums1[it1-1];
             int l2= it2==0 ? int.MinValue : nums2[it2-1];
             int r1= it1==n ? int.MaxValue : nums1[it1];
             int r2= it2==m ? int.MaxValue : nums2[it2];
             
             if(l1<=r2 && l2<=r1) {
                 if((m+n)%2==0) return (Math.Max(l1,l2)+Math.Min(r1,r2))/2.0;
                 else return (Math.Max(l1,l2));
             }
             
             else if(l1>r2) high=it1-1;
             else low=it1+1;
         }
        
        return 0.0;
    }
}