#include <iostream>
#include <vector>
using namespace std;
#define ll long long

ll solve(vector<int> a, int n)
{
    ll ans = 0, sum = 0;
    int i = 0, j = 0;

    while (a[i] < 0)
        i++;
    j = i;

    while (i < n && j < n)
    {
        sum += a[j];

        if (sum >= 0)
            j++;
        else
        {
            int k = i, neg = 0;
            while (i < j)
            {
                if (a[i] < 0)
                {
                    neg++;
                    int times = (i - k) * (j - i);
                    ans += times * a[i];
                }
                else
                {
                    int times = (i - k + 1) * (j - i) - neg;
                    ans += times * a[i];
                }

                i++;
            }

            sum = 0;
            while (a[i] < 0)
                i++;
            j = i;
        }
    }

    int k = i, neg = 0;
    while (i < n)
    {
        if (a[i] < 0)
        {
            neg++;
            int times = (i - k) * (n - i);
            ans += times * a[i];
        }
        else
        {
            int times = (i - k + 1) * (n - i) - neg;
            ans += times * a[i];
        }

        i++;
    }

    return ans;
}

int main()
{
    int t;
    cin >> t;

    for (int x = 1; x <= t; x++)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        cout << "Case #" << x << ": " << solve(a, n) << endl;
    }

    return 0;
}