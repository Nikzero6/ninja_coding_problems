#include <iostream>
using namespace std;

bool check_num(int a[], int size, int i, int num)
{
    if (size == i)
        return false;

    if (a[i] == num)
        return true;

    return check_num(a, size, i + 1, num);
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

    cout << check_num(a, n, 0, num) << endl;

    return 0;
}