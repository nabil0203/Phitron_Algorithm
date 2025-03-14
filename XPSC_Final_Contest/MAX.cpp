// https://www.hackerrank.com/contests/phitron-problem-solvers-club-final-contest-batch-6/challenges/max-15

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    priority_queue<int> pq;
    map<int, int> mp;

    while (t--)
    {
        int x;
        cin >> x;

        if (x == 1)
        {
            int a;
            cin >> a;
            mp[a]++;
            pq.push(a);
        }
        
        else if (x == 2)
        {
            while (!pq.empty() && mp[pq.top()] == 0)
            {
                pq.pop();
            }

            if (pq.empty())
            {
                cout << "empty" << endl;
            }
            else
            {
                cout << pq.top() << endl;
                mp[pq.top()]--;
                pq.pop();
            }
        }
    }
    return 0;
}
