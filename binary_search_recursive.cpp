#include <iostream>
using namespace std;

int binary_search(int a[], int n, int x)
{
    if (n == 0)
        return -1;

    int mid = n / 2;

    if (a[mid] == x)
        return mid;
    else if (mid < x)
        return binary_search(a + mid + 1, n / 2 + (n % 2 - 1), x);
    else
        return binary_search(a, n / 2, x);
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int x;
    cin >> x;

    cout << binary_search(a, n, x) << endl;
    return 0;
}