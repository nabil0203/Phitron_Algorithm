// print 1-5


#include <bits/stdc++.h>
using namespace std;

void print(int a)
{

    if (a > 5)
    {
        return;
    }

    cout << a << " ";

    print(a + 1);
}

int main()
{
    int a;
    cin >> a;           // 1

    print(a);

    return 0;
}