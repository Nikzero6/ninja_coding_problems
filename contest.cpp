#include <iostream>
#include <vector>
using namespace std;

int pos[10001];

int solve(vector<int> a, int n, int m, int d)
{
    int ans = INT_MAX;

    for (int i = 0; i < m - 1; i++)
    {
        if (pos[a[i]] >= pos[a[i + 1]] || pos[a[i]] + d < pos[a[i + 1]])
            return 0;

        int move1 = pos[a[i + 1]] - pos[a[i]];
        int move2 = pos[a[i]] + d - pos[a[i + 1]] + 1;
        int posb_shifts = n - pos[a[i + 1]] + pos[a[i]] - 1;

        if (move2 < move1 && posb_shifts >= move2)
            ans = min(ans, move2);
        else
            ans = min(ans, move1);
    }

    return ans;
}

int main()
{
    int t;
    cin >> t;

    while (t)
    {
        int n, m, d;
        cin >> n >> m >> d;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            pos[x] = i;
        }

        vector<int> a(m);
        for (int i = 0; i < m; i++)
            cin >> a[i];

        cout << solve(a, n, m, d) << endl;
        t--;
    }
}
