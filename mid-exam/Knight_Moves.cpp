// https://www.hackerrank.com/contests/mid-term-exam-a-introduction-to-algorithms-a-batch-06/challenges/knight-moves-2

#include <bits/stdc++.h>
using namespace std;

char grid[105][105];

bool visited_array[105][105];

int level[105][105];

vector<pair<int, int>> d = {{2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {2, 1}, {1, 2}, {-1, 2}};

int n, m;

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
    {
        return false;
    }
    else
        return true;
}

void BFS(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});

    visited_array[si][sj] = true;

    level[si][sj] = 0;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();

        int par_i = par.first;
        int par_j = par.second;

        for (int i = 0; i < 8; i++)
        {
            int ci = par_i + d[i].first;
            int cj = par_j + d[i].second;

            if (valid(ci, cj) && !visited_array[ci][cj])
            {
                q.push({ci, cj});
                visited_array[ci][cj] = true;
                level[ci][cj] = level[par_i][par_j] + 1;
            }
        }
    }
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> m;

        int si, sj, di, dj;

        cin >> si >> sj;
        cin >> di >> dj;

        memset(visited_array, false, sizeof(visited_array));
        memset(level, -1, sizeof(level));

        BFS(si, sj);

        cout << level[di][dj] << endl;
    }

    return 0;
}