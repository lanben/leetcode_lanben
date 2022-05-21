class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
	unordered_map<int,int> count;
        for(int i:nums){
       		count[i]+=1;
            if(count[i]==2){
				return i;
			}
        }
        return 0;
    }
};