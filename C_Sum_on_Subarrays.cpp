#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        int pos = 0;

        for (int i = 1; i <= n; i++)
        {
            if (pos + i <= k)
            {
                pos += i;
                cout << "2 ";
            }
            else if (pos < k)
            {
                int rem_pos = k - pos;
                int need_neg_left = i - 1 - rem_pos;
                pos = k;
                cout << -2 * (need_neg_left)-1 << " ";
            }
            else
            {
                cout << "-100 ";
            }
        }
        cout << endl;
    }

    return 0;
}