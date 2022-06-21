#include <iostream>
using namespace std;

bool split_array(int a[], int n, int i, int lsum, int rsum)
{
    if (i == n)
        return lsum == rsum;

    if (a[i] % 5 == 0)
        lsum += a[i];
    else if (a[i] % 3 == 0)
        rsum += a[i];
    else
    {
        return split_array(a, n, i + 1, lsum + a[i], rsum) || split_array(a, n, i + 1, lsum, rsum + a[i]);
    }

    return split_array(a, n, i + 1, lsum, rsum);
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << split_array(a, n, 0, 0, 0);

    return 0;
}