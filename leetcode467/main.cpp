/*
author:lanben
date:2022/5/25
*/
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int l=p.length();
        vector<int> dp(26,0);//存储以字母为结尾的子串的个数
        int sublen=1;
        dp[p[0]-'a']=1;
        if(l==1) return 1;
        for(int i=1;i<l;i++){
            if(p[i]-p[i-1]==1||p[i]-p[i-1]==-25){
                sublen++;
                dp[p[i]-'a']=max(dp[p[i]-'a'],sublen);
            }
            else{
                sublen=1;
                dp[p[i]-'a']=max(1,dp[p[i]-'a']);
            }
        }
        int ans=0;
        for(int i=0;i<26;i++){
            ans+=dp[i];
        }
        return ans;
    }
};