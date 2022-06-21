#include <iostream>
using namespace std;

int *intersection(int a[], int n, int b[], int m)
{
    int *ans = new int[min(n, m)];

    sort(a, a + n);
    sort(b, b + m);

    for (int i = 0, j = 0, k = 0; i < n && j < m;)
    {
        if (a[i] == b[j])
        {
            ans[k] = a[i];
            i++;
            j++;
            k++;
        }
        else if (a[i] > b[j])
        {
            j++;
        }
        else
        {
            i++;
        }
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

    int m;
    cin >> m;
    int b[m];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    int *ans = intersection(a, n, b, m);

    for (int i = 0; i < min(m, n); i++)
        cout << ans[i];

    return 0;
}