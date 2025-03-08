// https://www.hackerrank.com/contests/final-exam-a-introduction-to-algorithms-a-batch-06/challenges/pile-of-word-37-3

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

        if (s1.size() != s2.size())
        {
            cout << "NO" << endl;
        }

        else
        {
            sort(s1.begin(), s1.end());
            sort(s2.begin(), s2.end());

            if (s1 != s2)
            {
                cout << "NO" << endl;
            }
            else
                cout << "YES" << endl;
        }
    }
    return 0;
}