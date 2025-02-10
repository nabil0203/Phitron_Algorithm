// https://leetcode.com/problems/island-perimeter/description/

// full island er poridhi




class Solution
{
public:
    bool vis[105][105];
    vector<pair<int, int>> d = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int n, m;
    int cnt;

    bool valid(int i, int j)
    {
        if (i < 0 || i >= n || j < 0 || j >= m)
            return false;
        return true;
    }

    void DFS(int si, int sj, vector<vector<int>> &grid)
    {

        vis[si][sj] = true;

        for (int i = 0; i < 4; i++)
        {
            int ci = si + d[i].first;
            int cj = sj + d[i].second;

            if (valid(ci, cj) == false)
                cnt++;

            else if (valid(ci, cj) == true && grid[ci][cj] == 0)
                cnt++;

            else if (valid(ci, cj) == true && !vis[ci][cj] && grid[ci][cj] == 1)
            {
                DFS(ci, cj, grid);
            }
        }
    }

    int islandPerimeter(vector<vector<int>> &grid)
    {
        cnt = 0;
        n = grid.size();    // number of row
        m = grid[0].size(); // number of col

        memset(vis, false, sizeof(vis));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (!vis[i][j] && grid[i][j] == 1)
                    DFS(i, j, grid);
        return cnt;
    }
};