#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    unordered_map<int, int> socks;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        socks[x]++;
    }

    int ans = 0;

    unordered_map<int, int>::iterator it = socks.begin();
    while (it != socks.end())
    {
        ans += it->second / 2;
        it++;
    }

    cout << ans << endl;

    return 0;
}