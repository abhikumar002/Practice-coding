public int FindDuplicate(int[] nums) {
        
        if(nums.Length > 1){
             
            int slow = nums[0];
            int fast = nums[nums[0]];

            while(slow != fast){
                slow = nums[slow];
                fast = nums[nums[fast]];
            }

            fast = 0;
            while(slow !=fast){
                slow = nums[slow];
                fast = nums[fast];
            }

            return slow;
        }

        return -1;
    }
