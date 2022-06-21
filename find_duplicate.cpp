#include <iostream>
using namespace std;

int duplicate(int a[], int n)
{
    int total_sum = 0;
    int formula_sum = ((n - 2) * (n - 1)) / 2;

    for (int i = 0; i < n; i++)
    {
        total_sum += a[i];
    }

    return total_sum - formula_sum; 
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << duplicate(a, n) << endl;

    return 0;
}