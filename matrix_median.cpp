#include <iostream>
#include <vector>
using namespace std;

int median(vector<vector<int>> &a, int r, int c)
{
    int low = INT_MAX, high = INT_MIN;

    for (int i = 0; i < r; i++)
        low = min(low, a[i][0]);

    for (int i = 0; i < r; i++)
        high = max(high, a[i][c - 1]);

    int half = (r * c) / 2;

    while (low <= high)
    {
        int count = 0;
        int mid = (high - low) / 2 + low;

        for (int i = 0; i < r; i++)
        {
            vector<int>::iterator it;

            it = upper_bound(a[i].begin(), a[i].end(), mid);
            count += it - a[i].begin();
        }

        if (count == half)
            return mid;
        else if (count < half)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    vector<vector<int>> a = {{1, 3, 5}, {2, 6, 9}, {3, 6, 9}};

    cout << median(a, 3, 3) << endl;

    return 0;
}