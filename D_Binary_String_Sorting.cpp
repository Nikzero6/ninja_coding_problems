#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define NUM (ll)1E12

ll solve(string s, char prev, ll count, ll i)
{
    if (i < 0)
        return 0;

    ll ans = 0;

    if (s[i] == '1')
    {
        if (prev == '1')
            ans = solve(s, s[i], count, i - 1);
        else
        {
            ans = min(count * (solve(s, prev, count, i - 1) + NUM), solve(s, prev, count, i - 1) + NUM + 1);
        }
    }
    else
    {
        ans = min(solve(s, prev, count, i - 1) + NUM + 1, solve(s, s[i], count + 1, i - 1));
    }

    return ans;
}

ll solve_dp(string s)
{
    ll count = 0;
    ll n = s.size();
    vector<ll> dp(n + 1);
    vector<ll> zero_pos;
    dp[n] = 0;

    for (ll i = n - 1; i >= 0; i--)
    {
        char c = s[i];

        if (c == '1')
        {
            ll remove_zero_cost = count * (NUM + 1);
            ll remove_curr_cost = NUM + 1;
            ll transpose_curr_cost = count * NUM;

            if (remove_zero_cost < remove_curr_cost && remove_zero_cost < transpose_curr_cost)
            {
                dp[i] = remove_zero_cost;
                count = 0;
            }
            else
            {
                dp[i] = dp[i + 1] + min(remove_curr_cost, transpose_curr_cost);
            }
        }
        else
        {
            zero_pos.push_back(i);
            dp[i] = dp[i + 1];
            count++;
        }
    }

    return dp[0];
}
// 0101
ll solve_real(string s)
{
    int n = s.size();
    int total_1 = 0, total_0 = 0;

    for (auto c : s)
        total_0 += (c == '0'), total_1 += (c == '1');

    if (!total_0 || !total_1)
        return 0;

    ll ans = min(total_0, total_1) * (NUM + 1);

    int left_0 = 0, left_1 = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
            left_0++;
        else
            left_1++;

        ll curr = 0;
        curr += 0;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        // cout << solve(s, '1', 0, s.size() - 1) << endl;
        cout << solve_real(s) << endl;
    }

    return 0;
}