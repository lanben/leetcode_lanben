//该代码为超时错误代码，使用二维数组存储状态
class Solution {
public:
    //用数组来存储各种state的取胜情况//1为胜，-1为负
    int n,t;
    //在函数外初始化vector,编译器无法区分这个vector是成员变量声明还是成员方法声明
    //vector<vector<int>> f= vector(1<<20 , vector<int> (2,0));
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if ((1 + maxChoosableInteger) * (maxChoosableInteger) / 2 < desiredTotal) {
            return false;
        }
        vector<vector<int>> res(1<<20,vector<int>(2,0));
        n=maxChoosableInteger;
        t=desiredTotal;
        return dfs(0,0,0,res)==1;
    }
    //state是一个用来存储取过数字情况的整数
    //total 是当前总和
    //k是回合数，默认先手为0，也就是第一位偶第二位奇数
    int dfs(int state,int total,int k,vector<vector<int>>& f){
        if(state==(1<<20)-1&&total<t) return -1;
        if(f[state][k%2]!=0) return f[state][k%2];
        int hope=k%2==0? 1:-1;
        for(int i=0;i<n;i++){
             if (((state >> i) & 1) == 1) continue;
            if (total + i + 1 >= t) return f[state][k % 2] = hope;
            if (dfs(state | (1 << i), total + i + 1, k + 1,f) == hope) return f[state][k % 2] = hope;
        
        }
        return f[state][k%2]=-hope;
    }
};