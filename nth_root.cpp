#include <iostream>
using namespace std;
#define MOD 1000000009

int NthRoot(int n, int m)
{
    if (n == 1)
        return m;

    int low = 0, high = m / n + m % n;

    while (low <= high)
    {
        int mid = (high - low) / 2 + low;
        long long p = 1;
        int x = 0;

        while (x < n)
        {
            p *= mid;
            if (p > MOD)
                break;
            x++;
        }

        if (p == m)
            return mid;
        else if (p < m)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    int n, m;
    cin >> n >> m;
    cout << NthRoot(n, m) << endl;
    return 0;
}