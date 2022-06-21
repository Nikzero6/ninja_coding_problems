#include <iostream>
using namespace std;
#include <unordered_map>

int pair_count(int a[], int size, int target)
{
    unordered_map<int, int> ump;
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (ump.find(target - a[i]) != ump.end())
            count++;

        ump[a[i]] = 1;
    }

    return count;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int target;
    cin >> target;

    cout << pair_count(a, n, target) << endl;
    return 0;
}