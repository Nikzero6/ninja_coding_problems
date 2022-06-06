#include <iostream>
using namespace std;
#include <vector>

void all_indices(int a[], int size, int i, int num, vector<int> &ans)
{
    if (i == size)
        return;

    if (a[i] == num)
        ans.push_back(i);

    return all_indices(a, size, i + 1, num, ans);
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int num;
    cin >> num;
    vector<int> ans;
    all_indices(a, n, 0, num, ans);

    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}