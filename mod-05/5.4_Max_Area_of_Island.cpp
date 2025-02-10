// https://leetcode.com/problems/max-area-of-island/description/

// je koyata island ase tar moddhe boro konta
// age count korte hobe koyta island ase
// then je koyta island ase, tar moddhe sb theke boro ta return korte hobe

class Solution
{
public:
    bool vis[55][55];
    vector<pair<int, int>> d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int n, m;
    int cnt, mx;

    bool valid(int i, int j)
    {
        if (i < 0 || i >= n || j < 0 || j >= m)
            return false;
        return true;
    }

    void DFS(int si, int sj, vector<vector<int>> &grid)
    {
        cnt++;
        vis[si][sj] = true;

        for (int i = 0; i < 4; i++)
        {
            int ci = si + d[i].first;
            int cj = sj + d[i].second;

            if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == 1)
            {
                DFS(ci, cj, grid);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        mx = 0;
        memset(vis, false, sizeof(vis));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (!vis[i][j] && grid[i][j] == 1)
                {
                    cnt = 0;
                    DFS(i, j, grid);
                    mx = max(mx, cnt);                              // comparing everytime the DFS is called
                }
        return mx;
    }
};