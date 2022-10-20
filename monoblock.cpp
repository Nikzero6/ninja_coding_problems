#include <iostream>
#include <vector>
using namespace std;
#define ll long long

ll solve(ll i, ll x, vector<ll> &a, ll &aws)
{
    ll n = a.size();
    ll left = (i - 1) ? a[i - 2] : -1;
    ll right = (i < n) ? a[i] : -1;
    ll curr = a[i - 1];

    if (curr == left)
        aws += (i - 1) * (n - i + 1);

    if (curr == right)
        aws += i * (n - i);

    a[i - 1] = x;
    curr = x;

    if (curr == left)
        aws -= (i - 1) * (n - i + 1);

    if (curr == right)
        aws -= (i) * (n - i);

    return aws;
}

ll awesome(vector<ll> a)
{

    ll n = a.size();
    ll prev = a[0];
    ll aws = ((n * (n + 1))) / 2;

    for (ll i = 0; i < n; i++)
    {
        if (prev != a[i])
        {
            aws += i * (n - i);
        }
        prev = a[i];
    }

    return aws;
}

int main()
{
    ll n, m;
    cin >> n >> m;

    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];

    ll aws = awesome(a);

    while (m)
    {
        ll i, x;
        cin >> i >> x;
        cout << solve(i, x, a, aws) << endl;
        m--;
    }

    return 0;
}