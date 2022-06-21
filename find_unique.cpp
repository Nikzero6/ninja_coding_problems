#include <iostream>
using namespace std;

int unique(int a[], int n)
{
    sort(a, a + n);
    for (int i = 0; i < n; i += 2)
    {
        if (a[i] != a[i + 1])
            return a[i];
    }

    return -1;
}
int xor_unique(int a[], int n)
{
    int ans = a[0];
    for (int i = 1; i < n; i++)
    {
        ans = ans ^ a[i];
    }

    return ans;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << xor_unique(a, n) << endl;
    return 0;
}