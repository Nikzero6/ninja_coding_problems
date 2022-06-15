#include <iostream>
using namespace std;
#include <vector>

void return_subsets(int a[], vector<vector<int>> &ds, vector<int> ans, int i, int size, int sum, int k)
{
    if (i == size || sum > k)
    {
        return;
    }

    if (sum == k)
    {
        ds.push_back(ans);
        return;
    }

    ans.push_back(a[i]);
    return_subsets(a, ds, ans, i + 1, size, sum + a[i], k);
    ans.pop_back();
    return_subsets(a, ds, ans, i + 1, size, sum, k);
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int k;
    cin >> k;
    vector<int> ans;
    vector<vector<int>> ds;
    return_subsets(a, ds, ans, 0, n, 0, k);

    for (auto it : ds)
    {
        for (auto vec : it)
        {
            cout << vec << " ";
        }
        cout << endl;
    }

    return 0;
}