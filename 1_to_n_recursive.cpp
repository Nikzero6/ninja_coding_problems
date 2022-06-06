#include <iostream>
using namespace std;

void print_n(int n)
{
    if (n == 0)
        return;

    print_n(n - 1);
    cout << n << " ";
}
int main()
{
    int n;
    cin >> n;

    print_n(n);

    return 0;
}