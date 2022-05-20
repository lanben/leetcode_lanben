/*
author:lanben
date:2022/5/20
*/
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<int> ans;
        //unordered_map<int,int> index;//<区间下限，编号>
        map<int,int> index;
        for(int i=0;i<n;i++){
            index[intervals[i][0]]=i;
        }
        //lower_bound() 函数用于在指定区域内查找不小于目标值的第一个元素
        for(int i=0;i<n;i++){
            auto it= index.lower_bound(intervals[i][1]);//map的成员函数，unordered_map没有
            if(it!= index.end()){
                ans.push_back(it->second);
            }
            else{
                ans.push_back(-1);
            }

        }
        return ans;
    }
};