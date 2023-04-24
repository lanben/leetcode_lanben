class Solution {
    public int[] twoSum(int[] nums, int target) {
        int size=nums.length;
        for(int i=0;i<size-1;i++){
            for(int j=1;j<size;j++){
                if(nums[j]==target-nums[i])
                return new int[]{i, j};
            }
        }
        return new int[0];
    }
}