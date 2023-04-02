#include <bits/stdc++.h>
using namespace std;
#define ll long long

void destroy(vector<vector<char>> &a, int m, int n, int src_i, int src_j)
{
    int pow = a[src_i][src_j] - '0';

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] >= '1' && a[i][j] <= '9')
                continue;

            if (abs(src_i - i) + abs(src_j - j) <= pow)
                a[i][j] = '.';
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;
    vector<vector<char>> a;

    for (int i = 0; i < m; i++)
    {
        vector<char> b(n);
        for (int j = 0; j < n; j++)
            cin >> b[j];

        a.push_back(b);
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            if (a[i][j] >= '1' && a[i][j] <= '9')
                destroy(a, m, n, i, j);
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] >= '1' && a[i][j] <= '9')
                a[i][j] = '.';
        }
    }

    for (auto it : a)
    {
        for (auto vec : it)
        {
            cout << vec;
        }
        cout << endl;
    }

    return 0;
}