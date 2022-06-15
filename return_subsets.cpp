#include <iostream>
using namespace std;
#include <vector>

void return_subsets(int a[], vector<vector<int>> &ds, vector<int> ans, int i, int size)
{   
    if (i == size)
    {
        ds.push_back(ans);
        return;
    }

    ans.push_back(a[i]);
    return_subsets(a, ds, ans, i + 1, size);
    ans.pop_back();
    return_subsets(a, ds, ans, i + 1, size);
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> ans;
    vector<vector<int>> ds;
    return_subsets(a, ds, ans, 0, n);

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