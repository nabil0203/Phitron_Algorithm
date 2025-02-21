// https://judge.phitron.io/contests/phitron-code-fest1-mock-batch06/problems/cm7a3uqb500g1qu01l3om8j8d

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        // vector<int> v(10005, 0);
        map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            int p;
            cin >> p;
            mp[p]++;
        }

        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            if (it->second % 2 != 0)
                cout << it->first;
        }
        cout << endl;
    }

    return 0;
}