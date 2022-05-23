/*思路来源于大佬宫水三叶，希望自己今后能独立思考出可行解
author:lanben
date:2022/5/23
*/
class Solution {
public:
    //用数组来存储各种state的取胜情况//1为胜，-1为负
    int n,t;
    //vector<vector<int>> f= vector(1<<20 , vector<int> (2,0));
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if ((1 + maxChoosableInteger) * (maxChoosableInteger) / 2 < desiredTotal) {
            return false;
        }
        vector<int> res(1<<20,0);
        n=maxChoosableInteger;
        t=desiredTotal;
        return dfs(0,0,res)==1;
    }
    //state是一个用来存储取过数字情况的整数
    //total 是当前总和
    int dfs(int state,int total,vector<int>& f){
        if(state==(1<<20)-1&&total<t) return -1;
        if(f[state]!=0) return f[state];
        
        for(int i=0;i<n;i++){
             if (((state >> i) & 1) == 1) continue;
            if (total + i + 1 >= t) return f[state] = 1;
            if (dfs(state | (1 << i), total + i + 1,f) == -1) return f[state] = 1;
        
        }
        return f[state]=-1;
    }
};