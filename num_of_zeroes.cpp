#include <iostream>
using namespace std;

int num_of_zeroes(int n, int count)
{
    if (n == 0)
        return count;

    if (n % 10 == 0)
        count++;

    return num_of_zeroes(n / 10, count);
}
int main()
{
    int n;
    cin >> n;

    cout << num_of_zeroes(n, 0);

    return 0;
}