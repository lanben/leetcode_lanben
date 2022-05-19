/*
author: lanben
date:2022/5/19
*/
class Solution {
public:
    int minMoves2(vector<int>& nums) {
		sort(nums.begin(),nums.end());
        int count=0;
        int n=nums.size();
        int target=nums[n/2];
        for(int i=0;i<n;i++){
			count+=abs(target-nums[i]);
		}
        return count;
    }
};