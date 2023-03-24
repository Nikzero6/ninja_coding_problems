#include <iostream>
#include <climits>
using namespace std;
#define MOD 1000000009
#define ll long long

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        ll sum = ((n + 1) * (n + 2)) / 2;
        sum = sum * sum - 1;
        ll sq_sum = INT_MAX;

        for (ll i = 1; i * i <= sum; i++)
        {
            if (sum % i)
                continue;

            ll j = sum / i;

            if ((i + j) % 2 || (i - j) % 2)
                continue;

            int a = (i + j) / 2, b = abs(i - j) / 2;

            if (sq_sum > a + b)
                sq_sum = a + b;
        }

        cout << (sq_sum % MOD) << endl;
        for (int i = 2; i <= n + 1; i++)
            cout << i << " ";
    }
    return 0;
}
