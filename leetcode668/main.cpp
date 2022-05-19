/*
author:lanben
date:2022/5/18
*/
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        //if(k>n*m) return -1;
        int l=1,r=m*n;
        int mid,ans;
        while(l<=r){
            mid=(l+r)>>1;
            if(check(m,n,k,mid)){
                ans=mid;//暂时存储ans，因为退出循环时的mid不一定是ans
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
    bool check(int m,int n,int k,int mid){
        int count=0;
        for(int i=1;i<=m;i++){
            count+=min(mid/i,n);
        }
        return count>=k;
    }
};