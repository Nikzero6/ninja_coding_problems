#include <iostream>
using namespace std;

int num_of_ways(int n)
{
    if (n == 0)
        return 1;

    if (n < 0)
        return 0;

    return num_of_ways(n - 1) +
           num_of_ways(n - 2) +
           num_of_ways(n - 3);
}
int main()
{
    int n;
    cin >> n;

    cout << num_of_ways(n) << endl;

    return 0;
}