// https://leetcode.com/problems/count-sub-islands/description/

// duita grid ase
// grid2 ee je island ase, same island grid1 eo ase kina
// je koyta same island ase oitai ans



class Solution {
    public:
        bool vis[505][505];
        vector<pair<int,int>> d = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        int n,m;
        bool flag;
    
        bool valid(int i, int j)
        {
            if(i<0 || i>=n || j<0 || j>=m)
                return false;
            return true;
        }
    
        void DFS(int si, int sj, vector<vector<int>>& grid1, vector<vector<int>>& grid2)
        {
            vis[si][sj] = true;
    
            if(grid1[si][sj] == 0)                                  // checking in grid1; if it is '0' then it means its not subisland
                flag = false;
    
            for(int i=0; i<4; i++)
            {
                int ci = si + d[i].first;
                int cj = sj + d[i].second;
    
                if(valid(ci, cj) && !vis[ci][cj] && grid2[ci][cj] == 1)
                    DFS(ci,cj,grid1,grid2);
            }
        }
    
        int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
            int cnt = 0;
            n = grid1.size();
            m = grid1[0].size();
            memset(vis, false, sizeof(vis));
    
            for(int i=0; i<n; i++)
                for(int j=0; j<m; j++)
                    if(!vis[i][j] && grid2[i][j]==1)
                    {   
                        flag = true;                                 // making True before DFS
                        DFS(i,j,grid1,grid2);
                        if(flag == true)                             // if it's still true after DFS, then it is a Subisland
                            cnt++;
                    }
            return cnt;
        }
    };