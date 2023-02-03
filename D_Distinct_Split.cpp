#include <iostream>
#include <string>
using namespace std;

int solve(int n, string s)
{
    int l[n] = {0}, r[n] = {0}, hash[26] = {0};

    for (int i = 0; i < n; i++)
    {
        int c = s[i] - 'a';
        if (!hash[c])
        {
            hash[c] = 1;
            l[i] = i == 0 ? 1 : l[i - 1] + 1;
        }
        else
            l[i] = l[i - 1];
    }

    int new_hash[26] = {0};

    for (int i = n - 1; i >= 0; i--)
    {
        int c = s[i] - 'a';
        if (!new_hash[c])
        {
            new_hash[c] = 1;
            r[i] = i == n - 1 ? 1 : r[i + 1] + 1;
        }
        else
            r[i] = r[i + 1];
    }

    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        ans = max(l[i] + r[i + 1], ans);
    }

    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        cout << solve(n, s) << endl;
    }

    return 0;
}