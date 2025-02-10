// https://leetcode.com/problems/find-if-path-exists-in-graph/description/

// component connected kina
// v-3.11
// similar concept


class Solution
{
public:
    vector<int> adj_list[200005];
    bool vis[200005];

    void DFS(int src)
    {
        vis[src] = true;

        for (int child : adj_list[src])
        {
            if (!vis[child])
            {
                DFS(child);
            }
        }
    }

    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {

        for (int i = 0; i < edges.size(); i++)                        // converting the edge list into adj_list
        {
            int a = edges[i][0];
            int b = edges[i][1];
            adj_list[a].push_back(b);
            adj_list[b].push_back(a);
        }

        memset(vis, false, sizeof(vis));
        DFS(source);

        if (vis[destination] == true)
            return true;
        else
            return false;
    }
};