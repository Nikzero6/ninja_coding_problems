#include <iostream>
#include <vector>
#include <set>
using namespace std;

int digit_sum(int i, vector<int> &a)
{
    int num = a[i], sum = 0;

    while (num)
    {
        int rem = num % 10;
        sum += rem;
        num /= 10;
    }

    return sum;
}

void update(vector<int> &a, set<int> &s, int l, int r)
{
    set<int>::iterator start = s.lower_bound(l), end = s.upper_bound(r);

    while (start != end)
    {
        int sum = digit_sum(*start, a);
        a[*start] = sum;

        if (sum <= 9)
            start = s.erase(start);
        else
            start++;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;

        vector<int> a(n);
        set<int> s;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] > 9)
                s.insert(s.end(), i);
        }

        for (int i = 0; i < q; i++)
        {
            int q_type;
            cin >> q_type;

            if (q_type == 1)
            {
                int l, r;
                cin >> l >> r;

                update(a, s, l - 1, r - 1);
            }
            else
            {
                int x;
                cin >> x;
                cout << a[x - 1] << endl;
            }
        }
    }

    return 0;
}
