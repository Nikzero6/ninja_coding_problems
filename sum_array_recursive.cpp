#include <iostream>
using namespace std;

int sum(int a[], int size, int count, int i)
{
    if (size == i)
        return count;

    i++;
    return sum(a, size, count + a[i - 1], i);
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << sum(a, n, 0, 0) << endl;
    return 0;
}