#include <iostream>
#include <vector>
#include <string>
using namespace std;

int solve(string s, string t)
{
    vector<int> a(27, 0), b(27, 0);

    for (auto c : s)
        a[c - 'a']++;

    for (auto c : t)
        b[c - 'a']++;

    int ans = 0;
    for (int i = 0; i < 27; i++)
    {
        if (a[i] && b[i])
        {
            ans = max(ans, min(a[i], b[i]));
        }
    }

    return ans;
}

int main()
{
    int t;
    cin >> t;

    while (t)
    {
        int n;
        cin>>n;
        string s, x;
        cin >> s >> x;
        cout << solve(s, x) << endl;
        t--;
    }
    return 0;
}