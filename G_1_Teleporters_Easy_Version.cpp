#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int solve(vector<ll> &a, ll i, ll n, ll c, ll ans)
{
    if (c <= 0)
        return ans;

    if (i == 0)
        return solve(a, i + 1, n, c - 1, ans);

    if (i == n - 1)
        return solve(a, i - 1, n, c - 1, ans);

    if (a[i] == -1 || a[i] > c)
    {
        ll ans1 = solve(a, i + 1, n, c - 1, ans);
        ll ans2 = solve(a, i - 1, n, c - 1, ans);
        return max(ans1, ans2);
    }
    else
    {
        ll temp = a[i];

        a[i] = -1;
        ll ans1 = a[i] <= c ? solve(a, 0, n, c - a[i], ans + 1) : 0;

        a[i] = temp;
        ll ans2 = solve(a, i + 1, n, c, ans);
        ll ans3 = solve(a, i - 1, n, c - 1, ans);

        return max(ans1, max(ans2, ans3));
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, c;
        cin >> n >> c;

        vector<ll> a(n + 1);
        for (ll i = 1; i <= n; i++)
            cin >> a[i];

        cout << solve(a, 0, n, c, 0) << endl;
    }

    return 0;
}