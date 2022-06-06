#include <iostream>
using namespace std;

// answers might become larger than int/long long capacity

long long xpowern(int x, int n)
{
    if (n == 0)
        return 1;

    long long smallAns = xpowern(x, n - 1);
    cout << "smallAns: " << smallAns << endl;

    return x * smallAns;
}

long long xpowern_optimized(int x, int n)
{
    if (n == 0)
        return 1;

    long long temp = xpowern_optimized(x, n / 2);
    cout << temp << endl;
    if (n % 2 == 0)
        return temp * temp;
    else
        return x * temp * temp;
}

int main()
{
    int x, n;
    cout << "Inputs: ";
    cin >> x >> n;

    cout << xpowern_optimized(x, n) << endl;

    return 0;
}