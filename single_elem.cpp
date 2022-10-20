#include <iostream>
#include <vector>
using namespace std;

int singleNonDuplicate(vector<int> &a)
{

    int l = 0, n = a.size(), h = n - 1;

    while (l <= h)
    {
        int m = (h - l) / 2 + l;

        if (l == h || (a[m] != a[m-1] && a[m] != a[m+1]))
            return a[m];
        else if (a[m] == a[l])
        {
            n = m - l;

            if (n % 2 == 0)
                h = m - 2;
            else
                l = m + 1;
        }
        else
        {
            n = m - l;

            if (n % 2 == 0)
                l = m + 2;
            else
                h = m - 1;
        }
    }

    return -1;
}

int main()
{
    vector<int> a = {1,
                     1,
                     2,
                     3,
                     3,
                     4,
                     4,
                     8,
                     8};

    cout << singleNonDuplicate(a) << endl;

    return 0;
}