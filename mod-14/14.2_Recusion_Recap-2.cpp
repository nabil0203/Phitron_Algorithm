// print 5-1


#include <bits/stdc++.h>
using namespace std;

void print(int a)
{

    if (a > 5)
    {
        return;
    }

    print(a + 1);
    
    cout << a << " ";               // cout after recursion
}

int main()
{
    int a;
    cin >> a;           // 1

    print(a);

    return 0;
}