#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#define itr map<int, int>::iterator
using namespace std;

int maximizeWin(vector<int> &a, int k)
{
    unordered_map<int, int> freq;
    map<int, int> pre;
    pre[a[0]] = 0;

    int count = 1, sum = 0, i = 1;
    for (; i < a.size(); i++)
    {
        if (a[i] == a[i - 1])
            count++;
        else
        {
            freq[a[i - 1]] = count;
            sum += count;
            pre[a[i]] = sum;
            count = 1;
        }
    }
    freq[a[i - 1]] = count;

    itr start = pre.begin();
    int max1 = 0, max2 = 0;

    while (start != pre.end())
    {
        itr end = --pre.upper_bound(start->first + k);

        int count = 0;

        if (end != start)
            count = end->second - start->second + freq[end->first];
        else
            count = freq[end->first];

        if (count > max1)
        {
            max2 = max1;
            max1 = count;
        }
        else if (count > max2)
        {
            max2 = count;
        }

        start = ++end;
    }

    return max1 + max2;
}

int main()
{
    freopen("input.txt", "r", stdin);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout
        << maximizeWin(a, k) << endl;

    return 0;
}