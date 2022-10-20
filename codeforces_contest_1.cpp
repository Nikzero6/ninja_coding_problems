#include <iostream>
using namespace std;

bool solve(int n, int m)
{
    if (n == 1)
    {
        if (m & 1)
            return false;
        else
            return true;
    }

    if (m == 1)
    {
        if (n & 1)
            return false;
        else
            return true;
    }

    for (int k = 2; k <= m; k += 2)
    {
        if (!solve(n, m - k + 1))
            return true;
    }

    for (int k = n - 1; k >= 1; k -= 2)
    {
        if (!solve(k, m))
            return true;
    }

    return false;
}

int main()
{
    int t;
    cin >> t;

    // for (int i = 0; i < t; i++)
    // {
    //     int n, m;
    //     cin >> n >> m;

    if (solve(999999999, 1000000000))
        cout << "Burenka" << endl;
    else
        cout << "Tonya" << endl;
    // }

    return 0;
}