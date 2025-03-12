// https://www.hackerrank.com/contests/phitron-problem-solvers-club-mock-contest/challenges/letters-in-order

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    sort(s.begin(), s.end());

    set<char> st;

    for(char ch : s)
    {
        st.insert(ch);
    }

    for(auto it = st.begin(); it != st.end(); it++)
    {
        cout << *it;
    }

    return 0;
}