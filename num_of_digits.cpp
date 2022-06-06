#include <iostream>
using namespace std;

int num_of_digit(long n, int count)
{
    if (n == 0)
        return count;

    return num_of_digit(n / 10, ++count);
}
int main()
{
    long n;
    cin >> n;

    cout << num_of_digit(n, 0) << endl;

    return 0;
}