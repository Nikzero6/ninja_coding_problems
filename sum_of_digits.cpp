#include <iostream>
using namespace std;

int sum(int n, int ans)
{
    if (n == 0)
        return ans;

    return sum(n / 10, ans + n % 10);
}
int main()
{
    int n;
    cin >> n;

    cout << sum(n, 0) << endl;
    return 0;
}