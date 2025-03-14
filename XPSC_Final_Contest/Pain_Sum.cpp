// https://www.hackerrank.com/contests/phitron-problem-solvers-club-final-contest-batch-6/challenges/pain-sum

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     long long int n, q;
//     cin >> n >> q;

//     while (q--)
//     {
//         long long int l, r, sum = 0;
//         cin >> l >> r;

//         for (int i = l; i <= r; i++)
//         {
//             sum += (i + 2) / 3;
//         }

//         cout << sum << endl;
//     }

//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long int n, q;
    cin >> n >> q;

    vector<long long> prefix(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        prefix[i] = prefix[i - 1] + (i + 2) / 3;
    }

    while (q--)
    {
        long long int l, r;
        cin >> l >> r;
        cout << prefix[r] - prefix[l - 1] << endl;
    }

    return 0;
}
