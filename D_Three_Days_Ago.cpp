#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool is_happy(vector<int> a)
{
    bool all_even = true;
    bool all_equal = true;
    int prev = -1;

    for (int i = 0; i < 10; i++)
    {
        if (a[i] % 2 != 0)
        {
            all_even = false;
            break;
        }
    }

    return all_even;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int n = s.size();
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        vector<int> a(10);
        for (int j = i; j < n; j++)
        {
            char c = s[j];
            a[c - '0']++;
            ans += is_happy(a);
        }
    }

    cout << ans << endl;
    return 0;
}