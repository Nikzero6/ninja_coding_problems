#include <iostream>
using namespace std;

int last_index(int a[], int size, int num, int i, int last)
{
    if (i == size)
        return last;

    if (a[i] == num)
        last = i;

    return last_index(a, size, num, i + 1, last);
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int num;
    cin >> num;

    cout << last_index(a, n, num, 0, -1) << endl;
    return 0;
}