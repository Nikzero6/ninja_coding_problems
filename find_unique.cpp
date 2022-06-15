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
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << unique(a, n) << endl;
    return 0;
}