#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll neg_count = 0, sum = 0, min_val = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            if (x < 0)
                neg_count++;
            sum += abs(x);
            min_val = min(min_val, abs(x));
        }

        if (neg_count % 2 == 0)
            cout << sum << endl;
        else
        {
            cout << (sum - 2 * min_val) << endl;
        }
    }

    return 0;
}