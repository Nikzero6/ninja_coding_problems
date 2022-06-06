#include <iostream>
using namespace std;

int multiply(int n, int m, int ans)
{
    if (m == 0)
        return ans;

    return multiply(n, m - 1, ans + n);
}

int main()
{
    int n, m;
    cin >> n >> m;

    cout << multiply(n, m, 0);

    return 0;
}