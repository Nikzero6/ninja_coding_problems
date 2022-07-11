#include <iostream>
#include <vector>
using namespace std;

int _solve(vector<int> &A, int B, int i, int ans)
{
    if (i == A.size())
        return 0;

    if (ans == B)
        return 1;

    int count = 0;
    ans = ans ^ A[i];

    count += _solve(A, B, i + 1, ans);

    ans = 0;
    count += _solve(A, B, i + 1, ans);

    return count;
}

int solve(vector<int> &A, int B)
{
    return _solve(A, B, 0, 0);
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int b;
    cin >> b;

    cout << solve(a, b);

    return 0;
}