#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        priority_queue<int> pq;

        int ans = 0;
        for (auto x : a)
        {
            if (x == 0 && pq.size() > 0)
            {
                ans += pq.top();
                pq.pop();
            }
            else
                pq.push(x);
        }

        cout << ans << endl;
    }

    return 0;
}