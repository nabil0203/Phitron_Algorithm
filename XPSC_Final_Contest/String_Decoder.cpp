// https://www.hackerrank.com/contests/phitron-problem-solvers-club-final-contest-batch-6/challenges/string-decoder-1-1

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        for (int i = 0; i < s.size(); i += 2)
        {
            char ch = s[i];
            int freq = s[i + 1] - '0';

            for (int i = 0; i < freq; i++)
            {
                cout << ch;
            }
        }
        cout << endl;
    }

    return 0;
}