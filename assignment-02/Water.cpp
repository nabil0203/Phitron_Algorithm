// https://www.hackerrank.com/contests/assignment-02-a-introduction-to-algorithms-a-batch-06/challenges/water-4-1

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

        long long int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int index1, index2;

        int mx1 = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (mx1 <= a[i])
            {
                mx1 = a[i];
                index1 = i;
            }
        }

        int mx2 = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (mx2 <= a[i] && i != index1)
            {
                mx2 = a[i];
                index2 = i;
            }
        }

        vector<int> index;
        index.push_back(index1);
        index.push_back(index2);

        sort(index.begin(), index.end());

        for (int i = 0; i < index.size(); i++)
        {
            cout << index[i] << " ";
        }

        cout << endl;
    }

    return 0;
}