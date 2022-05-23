/*
author:lanben
date:2022/5/23
*/
class Solution {
public:
    //方向矩阵
    int dirs[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
    int cutOffTree(vector<vector<int>>& forest) {
        int m=forest.size();
        int n=forest[0].size();
        //遍历，找到所有的树
        vector<pair<int,int>> tree;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(forest[i][j]>1) tree.emplace_back(i,j);
            }
        }
        //对树按高度排序
        sort(tree.begin(),tree.end(),[&](const pair<int, int> & a, const pair<int, int> & b) {
            return forest[a.first][a.second] < forest[b.first][b.second];
        });
        int sx=0;
        int sy=0;
        int ans=0;
        int size = tree.size();
        for(int k=0;k<size;k++){
            int step=bfs(sx,sy,tree[k].first,tree[k].second,forest);
            if(step==-1) return -1;
            else{
                ans+=step;
                sx=tree[k].first;
                sy=tree[k].second;
            }
        }
        return ans;

    }
    //广度优先搜索策略，不断更新起点终点，找从一棵树到下一颗树的最短路径
    int bfs(int sx,int sy,int dx,int dy,vector<vector<int>>& forest){
        if(sx==dx&&sy==dy) return 0;
        int m=forest.size();
        int n=forest[0].size();
        int step=0;
        queue<pair<int,int>> q;
        q.emplace(sx, sy);
        vector<vector<bool>> visit(m,vector<bool>(n,false));
        visit[sx][sy]=true;
        while(!q.empty()){
            step++;
            int size=q.size();
            for(int i=0;i<size;i++){
                int cx=q.front().first;
                int cy=q.front().second;
                q.pop();
                for(int j=0;j<4;j++){
                    int x=cx+dirs[j][0];
                    int y=cy+dirs[j][1];
                    if(x>=0&&x<m&&y>=0&&y<n&&!visit[x][y]&&forest[x][y]>0){
                        if(x==dx&&y==dy) return step;
                        else{
                            q.emplace(x,y);
                            visit[x][y]=true;
                        }
                    }
                }
            }
        } 
        return -1;
    }
};