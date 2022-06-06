#include <iostream>
using namespace std;
#include <math.h>

float geometric_sum(int n, float ans)
{
    if (n == 0)
        return ans;

    ans = ans + 1 / pow(2, n);

    return geometric_sum(n - 1, ans);
}
int main()
{
    int n;
    cin >> n;

    cout << geometric_sum(n, 1) << endl;
    return 0;
}