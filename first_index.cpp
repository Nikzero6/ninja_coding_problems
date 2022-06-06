#include <iostream>
using namespace std;

int first_index(int a[], int size, int i, int num)
{
    if (i == size)
        return -1;

    if (a[i] == num)
        return i;

    return first_index(a, size, i + 1, num);
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

    cout << first_index(a, n, 0, num) << endl;
    return 0;
}